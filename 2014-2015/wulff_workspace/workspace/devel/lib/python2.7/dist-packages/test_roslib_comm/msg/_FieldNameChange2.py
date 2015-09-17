"""autogenerated by genpy from test_roslib_comm/FieldNameChange2.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import test_roslib_comm.msg

class FieldNameChange2(genpy.Message):
  _md5sum = "dde34a89b93706fc183fd13c24ae090a"
  _type = "test_roslib_comm/FieldNameChange2"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """SameSubMsg1 b
================================================================================
MSG: test_roslib_comm/SameSubMsg1
int32 a
float32 b
string c
uint64[10] d
float64[] e
"""
  __slots__ = ['b']
  _slot_types = ['test_roslib_comm/SameSubMsg1']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       b

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(FieldNameChange2, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.b is None:
        self.b = test_roslib_comm.msg.SameSubMsg1()
    else:
      self.b = test_roslib_comm.msg.SameSubMsg1()

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_if.pack(_x.b.a, _x.b.b))
      _x = self.b.c
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_struct_10Q.pack(*self.b.d))
      length = len(self.b.e)
      buff.write(_struct_I.pack(length))
      pattern = '<%sd'%length
      buff.write(struct.pack(pattern, *self.b.e))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.b is None:
        self.b = test_roslib_comm.msg.SameSubMsg1()
      end = 0
      _x = self
      start = end
      end += 8
      (_x.b.a, _x.b.b,) = _struct_if.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.b.c = str[start:end].decode('utf-8')
      else:
        self.b.c = str[start:end]
      start = end
      end += 80
      self.b.d = _struct_10Q.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sd'%length
      start = end
      end += struct.calcsize(pattern)
      self.b.e = struct.unpack(pattern, str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_if.pack(_x.b.a, _x.b.b))
      _x = self.b.c
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(self.b.d.tostring())
      length = len(self.b.e)
      buff.write(_struct_I.pack(length))
      pattern = '<%sd'%length
      buff.write(self.b.e.tostring())
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.b is None:
        self.b = test_roslib_comm.msg.SameSubMsg1()
      end = 0
      _x = self
      start = end
      end += 8
      (_x.b.a, _x.b.b,) = _struct_if.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.b.c = str[start:end].decode('utf-8')
      else:
        self.b.c = str[start:end]
      start = end
      end += 80
      self.b.d = numpy.frombuffer(str[start:end], dtype=numpy.uint64, count=10)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sd'%length
      start = end
      end += struct.calcsize(pattern)
      self.b.e = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=length)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_10Q = struct.Struct("<10Q")
_struct_if = struct.Struct("<if")
