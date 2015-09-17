"""autogenerated by genpy from test_roscpp/LatencyMessage.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class LatencyMessage(genpy.Message):
  _md5sum = "be90d117303321f392404ed7edeb7c8c"
  _type = "test_roscpp/LatencyMessage"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """float64 publish_time
float64 receipt_time
uint64 count
uint32 thread_index
uint8[] array


"""
  __slots__ = ['publish_time','receipt_time','count','thread_index','array']
  _slot_types = ['float64','float64','uint64','uint32','uint8[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       publish_time,receipt_time,count,thread_index,array

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(LatencyMessage, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.publish_time is None:
        self.publish_time = 0.
      if self.receipt_time is None:
        self.receipt_time = 0.
      if self.count is None:
        self.count = 0
      if self.thread_index is None:
        self.thread_index = 0
      if self.array is None:
        self.array = ''
    else:
      self.publish_time = 0.
      self.receipt_time = 0.
      self.count = 0
      self.thread_index = 0
      self.array = ''

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
      buff.write(_struct_2dQI.pack(_x.publish_time, _x.receipt_time, _x.count, _x.thread_index))
      _x = self.array
      length = len(_x)
      # - if encoded as a list instead, serialize as bytes instead of string
      if type(_x) in [list, tuple]:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 28
      (_x.publish_time, _x.receipt_time, _x.count, _x.thread_index,) = _struct_2dQI.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      self.array = str[start:end]
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
      buff.write(_struct_2dQI.pack(_x.publish_time, _x.receipt_time, _x.count, _x.thread_index))
      _x = self.array
      length = len(_x)
      # - if encoded as a list instead, serialize as bytes instead of string
      if type(_x) in [list, tuple]:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 28
      (_x.publish_time, _x.receipt_time, _x.count, _x.thread_index,) = _struct_2dQI.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      self.array = str[start:end]
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_2dQI = struct.Struct("<2dQI")
