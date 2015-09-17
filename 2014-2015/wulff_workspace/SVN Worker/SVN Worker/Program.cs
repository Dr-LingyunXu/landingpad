/*************************************************************************//**
 * @file Program.CS
 *
 * @brief SOURCE - sender file.
 *
 * @mainpage SVN Listener
 *
 * @section course_section CSC 465
 *
 * @author Alex Wulff
 *
 * @date November 10th
 *
 * @par Professor:
 *         Dr. Jeff McGough
 *
 * @par Course:
 *         CSC 465 - M001 - Tues / Thurs - 9:00am
 *
 * @par Location:
 *         McLaury - 304
 *
 * @section program_section Program Information
 *
 * @details
 * This automated program is intended to help trace breaks as 
 * well as general commit information by the team.  Requires a VM
 * calibrated to a specific IP to handle the build and testing environment.
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      (windows) - use visual studio and the sln provided.
 *
 * @par Usage:
 @verbatim
 rosrun api ApiSender
 @endverbatim
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 *
 * @par Modifications and Development Timeline:
 @verbatim
 Date              Modification
 ----------------  --------------------------------------------------------------
 * March 8th		Finished structure to test performance of sam's code
 *
 @endverbatim
 *
 ******************************************************************************/
 
using SharpSvn;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Net;
using System.Net.Mail;
using System.Text;
using Tamir.SharpSsh;

 
 
namespace SVN_Worker
{
	/*****************************************************************************
     * @author Alex Wulff
     *
     * @par Description:
     * This class is the foundation of a C# program.  It will simply queue a thread
     * and begin executions every 50 minutes
     *
     *
     *****************************************************************************/
    class Program
    {        

        static void Main(string[] args)
        {
            while (true)
            {
                Runner r = new Runner();
                r.Run();
                // sleep
                System.Threading.Thread.Sleep(3000000);
            }

        }

    }

	
	/*****************************************************************************
     * @author Alex Wulff
     *
     * @par Description:
     * This class is the executor of performance and testing on the VM.
	 * All this will do is send off the requests to the VM for build and
	 * test validation and email as new commits arrive and/or should a
	 * build break.
     *
     *****************************************************************************/
    public class Runner
    {
        private const string _Username = "alex.wulff@mines.sdsmt.edu";
        private const string _Password = "XXXXXXXXXXXX";
        private const string _VMUsername = "UUUUUUUUUUUU";
        private const string _VMPassword = "PPPPPPPPPPPP";
        private const string _SSHIP = "INTERNET_STUFFS";


        private Dictionary<string, int> _ID = new Dictionary<string, int>() 
                                              { 
                                              { "Charles" , 7087282 } , { "Hafiza" , 7024870 }, 
                                              { "Julian" , 1991875 } , { "Sam" , 7082185}, 
                                              { "Colter" , 7093860 } , { "Alex" , 7088881} 
                                              };
        private Collection<string> _CommitLog;

        private string _ErrorMessages = "";

        private string _ErrorLog;
        private static Dictionary<string, string> _UpdateMailList = new Dictionary<string, string>()
                                              {
                                                  {"Charles", "Charles.Parsons@mines.sdsmt.edu"},
                                                  {"Hafiza", "Hafiza.Farzami@mines.sdsmt.edu"},
                                                  {"Julian", "Julian.Brackins@mines.sdsmt.edu"},
                                                  {"Colter", "Colter.Assman@mines.sdsmt.edu"},
                                                  {"Alex", "Alex.Wulff@mines.sdsmt.edu"},
                                                  {"Jeff", "Jeff.McGough@sdsmt.edu"},
                                              };
        private static Dictionary<string, string> _BrokenMailList = new Dictionary<string, string>()
                                              {
                                                  {"Charles", "Charles.Parsons@mines.sdsmt.edu"},
                                                  {"Hafiza", "Hafiza.Farzami@mines.sdsmt.edu"},
                                                  {"Julian", "Julian.Brackins@mines.sdsmt.edu"},
                                                  {"Colter", "Colter.Assman@mines.sdsmt.edu"},
                                                  {"Alex", "Alex.Wulff@mines.sdsmt.edu"},
                                              };

        private static string _ErrorMsg = "Who done broke the build?!?!?!";
        private static string _LogMsg = "This is the new sh!t (sorry Mr. Manson)";

        private string _File;

        public Runner()
        {

        }

			/*****************************************************************************
     * @author Alex Wulff
     *
     * @par Description:
     * This method handles executions every 50 minutes, and finds logs and reports
	 * breaks in builds.
     *
     *****************************************************************************/
        public void Run()
        {
            _File = string.Format("{0}\\{1}", Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData), "Commits.txt");
            _CommitLog = new Collection<string>();
            
            Collection<SvnLogEventArgs> slea = new Collection<SvnLogEventArgs>();

            using (SvnClient client = new SvnClient())
            {
                client.Authentication.DefaultCredentials = new NetworkCredential("7088881", "080419877088881");

                Uri svnrepo = new Uri("http://dev.mcs.sdsmt.edu/repos/srdesign1415/robots/trunk/landingpad/");

                client.GetLog(svnrepo, out slea);
            }

            //client.GetLog("http://dev.mcs.sdsmt.edu/repos/srdesign1415/robots/trunk/landingpad/", out slea);


            foreach (SvnLogEventArgs s in slea)
            {
                int id;
                bool success = int.TryParse(s.Author, out id);
                string name = "";
                if (success && _ID.ContainsValue(id))
                {
                    foreach (string peeps in _ID.Keys)
                    {
                        if (_ID[peeps] == id)
                        {
                            name = peeps;
                            break;
                        }                            
                    }
                        
                    _CommitLog.Add(string.Format("=== {0} : {1} : {2} : {3} ====", s.Revision, name, s.Time, s.LogMessage).ToString());
                }
                else
                {
                    _CommitLog.Add(string.Format("=== {0} : {1} : {2} : {3} ====", s.Revision, s.Author, s.Time, s.LogMessage).ToString());
                }
            }

            if (IsLatest())
            {
                return;
            }
            else
            {
                // write to file.
                WriteLocal();

                // do mailing and checking of builds / unit tests.
                MailNewCommits();

                if (!BuildSuccess())
                {
                    MailSomeoneIsGonnaGetIt();
                }
            }
            
        }

	/*****************************************************************************
     * @author Alex Wulff
     *
     * @par Description:
     * This method simply checks to see if the commit saved is the most recent made.
     *
     *****************************************************************************/
        private bool IsLatest()
        {
            if (!File.Exists(_File))
            {
                return false;
            }
            else
            {
                string line;
                using (StreamReader sr = new StreamReader(_File))
                {
                    line = sr.ReadLine();
                }
                if (line == _CommitLog[0])
                {
                    return true;
                }
            }
            return false;
        }

	/*****************************************************************************
     * @author Alex Wulff
     *
     * @par Description:
     * This method writes the most recent log to a local cache for later use.
     *
     *****************************************************************************/
        private void WriteLocal()
        {
            using (StreamWriter sw = new StreamWriter(_File, false))
            {
                sw.WriteLine(_CommitLog[0]);
            }
        }
	/*****************************************************************************
     * @author Alex Wulff
     *
     * @par Description:
     * This method sends an email log message with all logs thus far.
     *
     *****************************************************************************/
        private void MailNewCommits()
        {
            foreach (KeyValuePair<string, string> person in _UpdateMailList)
            {
                using (System.Net.Mail.MailMessage message = new System.Net.Mail.MailMessage())
                {
                    message.To.Add(person.Value);
                    message.Subject = _LogMsg;
                    message.From = new System.Net.Mail.MailAddress(_UpdateMailList["Alex"]);
                    message.Body = "New Commits to follow";

                    foreach(string s in _CommitLog)
                    {
                        message.Body = message.Body + "\r\n" + s;
                    }

                    var smtp = new SmtpClient
                    {
                        Host = "smtp.gmail.com",
                        Port = 587,
                        EnableSsl = true,
                        DeliveryMethod = SmtpDeliveryMethod.Network,
                        UseDefaultCredentials = false,
                        Credentials = new NetworkCredential(_Username, _Password)
                    };
                    smtp.Send(message);
                }
            }
        }

		/*****************************************************************************
     * @author Alex Wulff
     *
     * @par Description:
     * This method sends an email threatining to abuse those who don't test their code.
     *
     *****************************************************************************/
        private void MailSomeoneIsGonnaGetIt()
        {
            foreach (KeyValuePair<string, string> person in _UpdateMailList)
            {
                using (System.Net.Mail.MailMessage message = new System.Net.Mail.MailMessage())
                {
                    message.To.Add(person.Value);
                    message.Subject = _ErrorMsg;
                    message.From = new System.Net.Mail.MailAddress(_UpdateMailList["Alex"]);
                    message.Body = string.Format("Aww Damn! That Shit is wack!\r\nLast commit was: {0}\r\n\r\n{1}", _CommitLog[0], _ErrorMessages).ToString();


                    var smtp = new SmtpClient
                    {
                        Host = "smtp.gmail.com",
                        Port = 587,
                        EnableSsl = true,
                        DeliveryMethod = SmtpDeliveryMethod.Network,
                        UseDefaultCredentials = false,
                        Credentials = new NetworkCredential(_Username, _Password)
                    };
                    smtp.Send(message);
                }
            }
        }

		/*****************************************************************************
     * @author Alex Wulff
     *
     * @par Description:
     * This method tests the vm for build success
     *
     *****************************************************************************/
        private bool BuildSuccess()
        {
            SshExec exec = new SshExec(_SSHIP, _VMUsername, _VMPassword);
            exec.Connect();
            string stdOut = null;
            string stdError = null;

            exec.RunCommand("./svnUpdate", ref stdOut, ref stdError);
            exec.RunCommand("./buildTests", ref stdOut, ref stdError);
            exec.RunCommand("./validateBuildTests", ref stdOut, ref stdError);

            if (stdError.Length != 0 || stdOut.Length != 0)
            {
                _ErrorMessages = string.Format("{0},{1}", stdOut, stdError).ToString();
            }
            else
            {
                _ErrorMessages = "";
                return true;
            }

            Console.WriteLine(stdOut);
            exec.Close();

            return false;
        }
    }
}
