"""autogenerated by genpy from trajectory_msgs/MultiDOFJointTrajectoryPoint.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import geometry_msgs.msg
import genpy

class MultiDOFJointTrajectoryPoint(genpy.Message):
  _md5sum = "3ebe08d1abd5b65862d50e09430db776"
  _type = "trajectory_msgs/MultiDOFJointTrajectoryPoint"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """# Each multi-dof joint can specify a transform (up to 6 DOF)
geometry_msgs/Transform[] transforms

# There can be a velocity specified for the origin of the joint 
geometry_msgs/Twist[] velocities

# There can be an acceleration specified for the origin of the joint 
geometry_msgs/Twist[] accelerations

duration time_from_start

================================================================================
MSG: geometry_msgs/Transform
# This represents the transform between two coordinate frames in free space.

Vector3 translation
Quaternion rotation

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 

float64 x
float64 y
float64 z
================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

================================================================================
MSG: geometry_msgs/Twist
# This expresses velocity in free space broken into its linear and angular parts.
Vector3  linear
Vector3  angular

"""
  __slots__ = ['transforms','velocities','accelerations','time_from_start']
  _slot_types = ['geometry_msgs/Transform[]','geometry_msgs/Twist[]','geometry_msgs/Twist[]','duration']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       transforms,velocities,accelerations,time_from_start

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(MultiDOFJointTrajectoryPoint, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.transforms is None:
        self.transforms = []
      if self.velocities is None:
        self.velocities = []
      if self.accelerations is None:
        self.accelerations = []
      if self.time_from_start is None:
        self.time_from_start = genpy.Duration()
    else:
      self.transforms = []
      self.velocities = []
      self.accelerations = []
      self.time_from_start = genpy.Duration()

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
      length = len(self.transforms)
      buff.write(_struct_I.pack(length))
      for val1 in self.transforms:
        _v1 = val1.translation
        _x = _v1
        buff.write(_struct_3d.pack(_x.x, _x.y, _x.z))
        _v2 = val1.rotation
        _x = _v2
        buff.write(_struct_4d.pack(_x.x, _x.y, _x.z, _x.w))
      length = len(self.velocities)
      buff.write(_struct_I.pack(length))
      for val1 in self.velocities:
        _v3 = val1.linear
        _x = _v3
        buff.write(_struct_3d.pack(_x.x, _x.y, _x.z))
        _v4 = val1.angular
        _x = _v4
        buff.write(_struct_3d.pack(_x.x, _x.y, _x.z))
      length = len(self.accelerations)
      buff.write(_struct_I.pack(length))
      for val1 in self.accelerations:
        _v5 = val1.linear
        _x = _v5
        buff.write(_struct_3d.pack(_x.x, _x.y, _x.z))
        _v6 = val1.angular
        _x = _v6
        buff.write(_struct_3d.pack(_x.x, _x.y, _x.z))
      _x = self
      buff.write(_struct_2i.pack(_x.time_from_start.secs, _x.time_from_start.nsecs))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.transforms is None:
        self.transforms = None
      if self.velocities is None:
        self.velocities = None
      if self.accelerations is None:
        self.accelerations = None
      if self.time_from_start is None:
        self.time_from_start = genpy.Duration()
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.transforms = []
      for i in range(0, length):
        val1 = geometry_msgs.msg.Transform()
        _v7 = val1.translation
        _x = _v7
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _struct_3d.unpack(str[start:end])
        _v8 = val1.rotation
        _x = _v8
        start = end
        end += 32
        (_x.x, _x.y, _x.z, _x.w,) = _struct_4d.unpack(str[start:end])
        self.transforms.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.velocities = []
      for i in range(0, length):
        val1 = geometry_msgs.msg.Twist()
        _v9 = val1.linear
        _x = _v9
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _struct_3d.unpack(str[start:end])
        _v10 = val1.angular
        _x = _v10
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _struct_3d.unpack(str[start:end])
        self.velocities.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.accelerations = []
      for i in range(0, length):
        val1 = geometry_msgs.msg.Twist()
        _v11 = val1.linear
        _x = _v11
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _struct_3d.unpack(str[start:end])
        _v12 = val1.angular
        _x = _v12
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _struct_3d.unpack(str[start:end])
        self.accelerations.append(val1)
      _x = self
      start = end
      end += 8
      (_x.time_from_start.secs, _x.time_from_start.nsecs,) = _struct_2i.unpack(str[start:end])
      self.time_from_start.canon()
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
      length = len(self.transforms)
      buff.write(_struct_I.pack(length))
      for val1 in self.transforms:
        _v13 = val1.translation
        _x = _v13
        buff.write(_struct_3d.pack(_x.x, _x.y, _x.z))
        _v14 = val1.rotation
        _x = _v14
        buff.write(_struct_4d.pack(_x.x, _x.y, _x.z, _x.w))
      length = len(self.velocities)
      buff.write(_struct_I.pack(length))
      for val1 in self.velocities:
        _v15 = val1.linear
        _x = _v15
        buff.write(_struct_3d.pack(_x.x, _x.y, _x.z))
        _v16 = val1.angular
        _x = _v16
        buff.write(_struct_3d.pack(_x.x, _x.y, _x.z))
      length = len(self.accelerations)
      buff.write(_struct_I.pack(length))
      for val1 in self.accelerations:
        _v17 = val1.linear
        _x = _v17
        buff.write(_struct_3d.pack(_x.x, _x.y, _x.z))
        _v18 = val1.angular
        _x = _v18
        buff.write(_struct_3d.pack(_x.x, _x.y, _x.z))
      _x = self
      buff.write(_struct_2i.pack(_x.time_from_start.secs, _x.time_from_start.nsecs))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.transforms is None:
        self.transforms = None
      if self.velocities is None:
        self.velocities = None
      if self.accelerations is None:
        self.accelerations = None
      if self.time_from_start is None:
        self.time_from_start = genpy.Duration()
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.transforms = []
      for i in range(0, length):
        val1 = geometry_msgs.msg.Transform()
        _v19 = val1.translation
        _x = _v19
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _struct_3d.unpack(str[start:end])
        _v20 = val1.rotation
        _x = _v20
        start = end
        end += 32
        (_x.x, _x.y, _x.z, _x.w,) = _struct_4d.unpack(str[start:end])
        self.transforms.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.velocities = []
      for i in range(0, length):
        val1 = geometry_msgs.msg.Twist()
        _v21 = val1.linear
        _x = _v21
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _struct_3d.unpack(str[start:end])
        _v22 = val1.angular
        _x = _v22
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _struct_3d.unpack(str[start:end])
        self.velocities.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.accelerations = []
      for i in range(0, length):
        val1 = geometry_msgs.msg.Twist()
        _v23 = val1.linear
        _x = _v23
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _struct_3d.unpack(str[start:end])
        _v24 = val1.angular
        _x = _v24
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _struct_3d.unpack(str[start:end])
        self.accelerations.append(val1)
      _x = self
      start = end
      end += 8
      (_x.time_from_start.secs, _x.time_from_start.nsecs,) = _struct_2i.unpack(str[start:end])
      self.time_from_start.canon()
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_4d = struct.Struct("<4d")
_struct_2i = struct.Struct("<2i")
_struct_3d = struct.Struct("<3d")
