// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ObstacleAvoidanceMessage.proto

#ifndef PROTOBUF_ObstacleAvoidanceMessage_2eproto__INCLUDED
#define PROTOBUF_ObstacleAvoidanceMessage_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2003000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2003000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_ObstacleAvoidanceMessage_2eproto();
void protobuf_AssignDesc_ObstacleAvoidanceMessage_2eproto();
void protobuf_ShutdownFile_ObstacleAvoidanceMessage_2eproto();

class ObstacleMessage;
class ObstacleMessageArray;
class VisionObstacleMessage;
class PathPlanningRequestMessage;
class PathPlanningResultMessage;

// ===================================================================

class ObstacleMessage : public ::google::protobuf::Message {
 public:
  ObstacleMessage();
  virtual ~ObstacleMessage();
  
  ObstacleMessage(const ObstacleMessage& from);
  
  inline ObstacleMessage& operator=(const ObstacleMessage& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const ObstacleMessage& default_instance();
  
  void Swap(ObstacleMessage* other);
  
  // implements Message ----------------------------------------------
  
  ObstacleMessage* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ObstacleMessage& from);
  void MergeFrom(const ObstacleMessage& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required int32 direction = 1 [default = -1];
  inline bool has_direction() const;
  inline void clear_direction();
  static const int kDirectionFieldNumber = 1;
  inline ::google::protobuf::int32 direction() const;
  inline void set_direction(::google::protobuf::int32 value);
  
  // required float distance = 2 [default = 0];
  inline bool has_distance() const;
  inline void clear_distance();
  static const int kDistanceFieldNumber = 2;
  inline float distance() const;
  inline void set_distance(float value);
  
  // required float certainty = 3 [default = 0];
  inline bool has_certainty() const;
  inline void clear_certainty();
  static const int kCertaintyFieldNumber = 3;
  inline float certainty() const;
  inline void set_certainty(float value);
  
  // @@protoc_insertion_point(class_scope:ObstacleMessage)
 private:
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  mutable int _cached_size_;
  
  ::google::protobuf::int32 direction_;
  float distance_;
  float certainty_;
  friend void  protobuf_AddDesc_ObstacleAvoidanceMessage_2eproto();
  friend void protobuf_AssignDesc_ObstacleAvoidanceMessage_2eproto();
  friend void protobuf_ShutdownFile_ObstacleAvoidanceMessage_2eproto();
  
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];
  
  // WHY DOES & HAVE LOWER PRECEDENCE THAN != !?
  inline bool _has_bit(int index) const {
    return (_has_bits_[index / 32] & (1u << (index % 32))) != 0;
  }
  inline void _set_bit(int index) {
    _has_bits_[index / 32] |= (1u << (index % 32));
  }
  inline void _clear_bit(int index) {
    _has_bits_[index / 32] &= ~(1u << (index % 32));
  }
  
  void InitAsDefaultInstance();
  static ObstacleMessage* default_instance_;
};
// -------------------------------------------------------------------

class ObstacleMessageArray : public ::google::protobuf::Message {
 public:
  ObstacleMessageArray();
  virtual ~ObstacleMessageArray();
  
  ObstacleMessageArray(const ObstacleMessageArray& from);
  
  inline ObstacleMessageArray& operator=(const ObstacleMessageArray& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const ObstacleMessageArray& default_instance();
  
  void Swap(ObstacleMessageArray* other);
  
  // implements Message ----------------------------------------------
  
  ObstacleMessageArray* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ObstacleMessageArray& from);
  void MergeFrom(const ObstacleMessageArray& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // repeated int32 direction = 1;
  inline int direction_size() const;
  inline void clear_direction();
  static const int kDirectionFieldNumber = 1;
  inline ::google::protobuf::int32 direction(int index) const;
  inline void set_direction(int index, ::google::protobuf::int32 value);
  inline void add_direction(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      direction() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_direction();
  
  // repeated float distance = 2;
  inline int distance_size() const;
  inline void clear_distance();
  static const int kDistanceFieldNumber = 2;
  inline float distance(int index) const;
  inline void set_distance(int index, float value);
  inline void add_distance(float value);
  inline const ::google::protobuf::RepeatedField< float >&
      distance() const;
  inline ::google::protobuf::RepeatedField< float >*
      mutable_distance();
  
  // repeated float certainty = 3;
  inline int certainty_size() const;
  inline void clear_certainty();
  static const int kCertaintyFieldNumber = 3;
  inline float certainty(int index) const;
  inline void set_certainty(int index, float value);
  inline void add_certainty(float value);
  inline const ::google::protobuf::RepeatedField< float >&
      certainty() const;
  inline ::google::protobuf::RepeatedField< float >*
      mutable_certainty();
  
  // @@protoc_insertion_point(class_scope:ObstacleMessageArray)
 private:
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  mutable int _cached_size_;
  
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > direction_;
  ::google::protobuf::RepeatedField< float > distance_;
  ::google::protobuf::RepeatedField< float > certainty_;
  friend void  protobuf_AddDesc_ObstacleAvoidanceMessage_2eproto();
  friend void protobuf_AssignDesc_ObstacleAvoidanceMessage_2eproto();
  friend void protobuf_ShutdownFile_ObstacleAvoidanceMessage_2eproto();
  
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];
  
  // WHY DOES & HAVE LOWER PRECEDENCE THAN != !?
  inline bool _has_bit(int index) const {
    return (_has_bits_[index / 32] & (1u << (index % 32))) != 0;
  }
  inline void _set_bit(int index) {
    _has_bits_[index / 32] |= (1u << (index % 32));
  }
  inline void _clear_bit(int index) {
    _has_bits_[index / 32] &= ~(1u << (index % 32));
  }
  
  void InitAsDefaultInstance();
  static ObstacleMessageArray* default_instance_;
};
// -------------------------------------------------------------------

class VisionObstacleMessage : public ::google::protobuf::Message {
 public:
  VisionObstacleMessage();
  virtual ~VisionObstacleMessage();
  
  VisionObstacleMessage(const VisionObstacleMessage& from);
  
  inline VisionObstacleMessage& operator=(const VisionObstacleMessage& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const VisionObstacleMessage& default_instance();
  
  void Swap(VisionObstacleMessage* other);
  
  // implements Message ----------------------------------------------
  
  VisionObstacleMessage* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const VisionObstacleMessage& from);
  void MergeFrom(const VisionObstacleMessage& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // repeated .ObstacleMessage obstacles = 1;
  inline int obstacles_size() const;
  inline void clear_obstacles();
  static const int kObstaclesFieldNumber = 1;
  inline const ::ObstacleMessage& obstacles(int index) const;
  inline ::ObstacleMessage* mutable_obstacles(int index);
  inline ::ObstacleMessage* add_obstacles();
  inline const ::google::protobuf::RepeatedPtrField< ::ObstacleMessage >&
      obstacles() const;
  inline ::google::protobuf::RepeatedPtrField< ::ObstacleMessage >*
      mutable_obstacles();
  
  // @@protoc_insertion_point(class_scope:VisionObstacleMessage)
 private:
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  mutable int _cached_size_;
  
  ::google::protobuf::RepeatedPtrField< ::ObstacleMessage > obstacles_;
  friend void  protobuf_AddDesc_ObstacleAvoidanceMessage_2eproto();
  friend void protobuf_AssignDesc_ObstacleAvoidanceMessage_2eproto();
  friend void protobuf_ShutdownFile_ObstacleAvoidanceMessage_2eproto();
  
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];
  
  // WHY DOES & HAVE LOWER PRECEDENCE THAN != !?
  inline bool _has_bit(int index) const {
    return (_has_bits_[index / 32] & (1u << (index % 32))) != 0;
  }
  inline void _set_bit(int index) {
    _has_bits_[index / 32] |= (1u << (index % 32));
  }
  inline void _clear_bit(int index) {
    _has_bits_[index / 32] &= ~(1u << (index % 32));
  }
  
  void InitAsDefaultInstance();
  static VisionObstacleMessage* default_instance_;
};
// -------------------------------------------------------------------

class PathPlanningRequestMessage : public ::google::protobuf::Message {
 public:
  PathPlanningRequestMessage();
  virtual ~PathPlanningRequestMessage();
  
  PathPlanningRequestMessage(const PathPlanningRequestMessage& from);
  
  inline PathPlanningRequestMessage& operator=(const PathPlanningRequestMessage& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const PathPlanningRequestMessage& default_instance();
  
  void Swap(PathPlanningRequestMessage* other);
  
  // implements Message ----------------------------------------------
  
  PathPlanningRequestMessage* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PathPlanningRequestMessage& from);
  void MergeFrom(const PathPlanningRequestMessage& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required float goToX = 1 [default = 0];
  inline bool has_gotox() const;
  inline void clear_gotox();
  static const int kGoToXFieldNumber = 1;
  inline float gotox() const;
  inline void set_gotox(float value);
  
  // required float goToY = 2 [default = 0];
  inline bool has_gotoy() const;
  inline void clear_gotoy();
  static const int kGoToYFieldNumber = 2;
  inline float gotoy() const;
  inline void set_gotoy(float value);
  
  // required float goToAngle = 3 [default = 0];
  inline bool has_gotoangle() const;
  inline void clear_gotoangle();
  static const int kGoToAngleFieldNumber = 3;
  inline float gotoangle() const;
  inline void set_gotoangle(float value);
  
  // @@protoc_insertion_point(class_scope:PathPlanningRequestMessage)
 private:
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  mutable int _cached_size_;
  
  float gotox_;
  float gotoy_;
  float gotoangle_;
  friend void  protobuf_AddDesc_ObstacleAvoidanceMessage_2eproto();
  friend void protobuf_AssignDesc_ObstacleAvoidanceMessage_2eproto();
  friend void protobuf_ShutdownFile_ObstacleAvoidanceMessage_2eproto();
  
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];
  
  // WHY DOES & HAVE LOWER PRECEDENCE THAN != !?
  inline bool _has_bit(int index) const {
    return (_has_bits_[index / 32] & (1u << (index % 32))) != 0;
  }
  inline void _set_bit(int index) {
    _has_bits_[index / 32] |= (1u << (index % 32));
  }
  inline void _clear_bit(int index) {
    _has_bits_[index / 32] &= ~(1u << (index % 32));
  }
  
  void InitAsDefaultInstance();
  static PathPlanningRequestMessage* default_instance_;
};
// -------------------------------------------------------------------

class PathPlanningResultMessage : public ::google::protobuf::Message {
 public:
  PathPlanningResultMessage();
  virtual ~PathPlanningResultMessage();
  
  PathPlanningResultMessage(const PathPlanningResultMessage& from);
  
  inline PathPlanningResultMessage& operator=(const PathPlanningResultMessage& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const PathPlanningResultMessage& default_instance();
  
  void Swap(PathPlanningResultMessage* other);
  
  // implements Message ----------------------------------------------
  
  PathPlanningResultMessage* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PathPlanningResultMessage& from);
  void MergeFrom(const PathPlanningResultMessage& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required float moveToX = 1 [default = 0];
  inline bool has_movetox() const;
  inline void clear_movetox();
  static const int kMoveToXFieldNumber = 1;
  inline float movetox() const;
  inline void set_movetox(float value);
  
  // required float moveToY = 2 [default = 0];
  inline bool has_movetoy() const;
  inline void clear_movetoy();
  static const int kMoveToYFieldNumber = 2;
  inline float movetoy() const;
  inline void set_movetoy(float value);
  
  // required float moveToAngle = 3 [default = 0];
  inline bool has_movetoangle() const;
  inline void clear_movetoangle();
  static const int kMoveToAngleFieldNumber = 3;
  inline float movetoangle() const;
  inline void set_movetoangle(float value);
  
  // @@protoc_insertion_point(class_scope:PathPlanningResultMessage)
 private:
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  mutable int _cached_size_;
  
  float movetox_;
  float movetoy_;
  float movetoangle_;
  friend void  protobuf_AddDesc_ObstacleAvoidanceMessage_2eproto();
  friend void protobuf_AssignDesc_ObstacleAvoidanceMessage_2eproto();
  friend void protobuf_ShutdownFile_ObstacleAvoidanceMessage_2eproto();
  
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];
  
  // WHY DOES & HAVE LOWER PRECEDENCE THAN != !?
  inline bool _has_bit(int index) const {
    return (_has_bits_[index / 32] & (1u << (index % 32))) != 0;
  }
  inline void _set_bit(int index) {
    _has_bits_[index / 32] |= (1u << (index % 32));
  }
  inline void _clear_bit(int index) {
    _has_bits_[index / 32] &= ~(1u << (index % 32));
  }
  
  void InitAsDefaultInstance();
  static PathPlanningResultMessage* default_instance_;
};
// ===================================================================


// ===================================================================

// ObstacleMessage

// required int32 direction = 1 [default = -1];
inline bool ObstacleMessage::has_direction() const {
  return _has_bit(0);
}
inline void ObstacleMessage::clear_direction() {
  direction_ = -1;
  _clear_bit(0);
}
inline ::google::protobuf::int32 ObstacleMessage::direction() const {
  return direction_;
}
inline void ObstacleMessage::set_direction(::google::protobuf::int32 value) {
  _set_bit(0);
  direction_ = value;
}

// required float distance = 2 [default = 0];
inline bool ObstacleMessage::has_distance() const {
  return _has_bit(1);
}
inline void ObstacleMessage::clear_distance() {
  distance_ = 0;
  _clear_bit(1);
}
inline float ObstacleMessage::distance() const {
  return distance_;
}
inline void ObstacleMessage::set_distance(float value) {
  _set_bit(1);
  distance_ = value;
}

// required float certainty = 3 [default = 0];
inline bool ObstacleMessage::has_certainty() const {
  return _has_bit(2);
}
inline void ObstacleMessage::clear_certainty() {
  certainty_ = 0;
  _clear_bit(2);
}
inline float ObstacleMessage::certainty() const {
  return certainty_;
}
inline void ObstacleMessage::set_certainty(float value) {
  _set_bit(2);
  certainty_ = value;
}

// -------------------------------------------------------------------

// ObstacleMessageArray

// repeated int32 direction = 1;
inline int ObstacleMessageArray::direction_size() const {
  return direction_.size();
}
inline void ObstacleMessageArray::clear_direction() {
  direction_.Clear();
}
inline ::google::protobuf::int32 ObstacleMessageArray::direction(int index) const {
  return direction_.Get(index);
}
inline void ObstacleMessageArray::set_direction(int index, ::google::protobuf::int32 value) {
  direction_.Set(index, value);
}
inline void ObstacleMessageArray::add_direction(::google::protobuf::int32 value) {
  direction_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
ObstacleMessageArray::direction() const {
  return direction_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
ObstacleMessageArray::mutable_direction() {
  return &direction_;
}

// repeated float distance = 2;
inline int ObstacleMessageArray::distance_size() const {
  return distance_.size();
}
inline void ObstacleMessageArray::clear_distance() {
  distance_.Clear();
}
inline float ObstacleMessageArray::distance(int index) const {
  return distance_.Get(index);
}
inline void ObstacleMessageArray::set_distance(int index, float value) {
  distance_.Set(index, value);
}
inline void ObstacleMessageArray::add_distance(float value) {
  distance_.Add(value);
}
inline const ::google::protobuf::RepeatedField< float >&
ObstacleMessageArray::distance() const {
  return distance_;
}
inline ::google::protobuf::RepeatedField< float >*
ObstacleMessageArray::mutable_distance() {
  return &distance_;
}

// repeated float certainty = 3;
inline int ObstacleMessageArray::certainty_size() const {
  return certainty_.size();
}
inline void ObstacleMessageArray::clear_certainty() {
  certainty_.Clear();
}
inline float ObstacleMessageArray::certainty(int index) const {
  return certainty_.Get(index);
}
inline void ObstacleMessageArray::set_certainty(int index, float value) {
  certainty_.Set(index, value);
}
inline void ObstacleMessageArray::add_certainty(float value) {
  certainty_.Add(value);
}
inline const ::google::protobuf::RepeatedField< float >&
ObstacleMessageArray::certainty() const {
  return certainty_;
}
inline ::google::protobuf::RepeatedField< float >*
ObstacleMessageArray::mutable_certainty() {
  return &certainty_;
}

// -------------------------------------------------------------------

// VisionObstacleMessage

// repeated .ObstacleMessage obstacles = 1;
inline int VisionObstacleMessage::obstacles_size() const {
  return obstacles_.size();
}
inline void VisionObstacleMessage::clear_obstacles() {
  obstacles_.Clear();
}
inline const ::ObstacleMessage& VisionObstacleMessage::obstacles(int index) const {
  return obstacles_.Get(index);
}
inline ::ObstacleMessage* VisionObstacleMessage::mutable_obstacles(int index) {
  return obstacles_.Mutable(index);
}
inline ::ObstacleMessage* VisionObstacleMessage::add_obstacles() {
  return obstacles_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::ObstacleMessage >&
VisionObstacleMessage::obstacles() const {
  return obstacles_;
}
inline ::google::protobuf::RepeatedPtrField< ::ObstacleMessage >*
VisionObstacleMessage::mutable_obstacles() {
  return &obstacles_;
}

// -------------------------------------------------------------------

// PathPlanningRequestMessage

// required float goToX = 1 [default = 0];
inline bool PathPlanningRequestMessage::has_gotox() const {
  return _has_bit(0);
}
inline void PathPlanningRequestMessage::clear_gotox() {
  gotox_ = 0;
  _clear_bit(0);
}
inline float PathPlanningRequestMessage::gotox() const {
  return gotox_;
}
inline void PathPlanningRequestMessage::set_gotox(float value) {
  _set_bit(0);
  gotox_ = value;
}

// required float goToY = 2 [default = 0];
inline bool PathPlanningRequestMessage::has_gotoy() const {
  return _has_bit(1);
}
inline void PathPlanningRequestMessage::clear_gotoy() {
  gotoy_ = 0;
  _clear_bit(1);
}
inline float PathPlanningRequestMessage::gotoy() const {
  return gotoy_;
}
inline void PathPlanningRequestMessage::set_gotoy(float value) {
  _set_bit(1);
  gotoy_ = value;
}

// required float goToAngle = 3 [default = 0];
inline bool PathPlanningRequestMessage::has_gotoangle() const {
  return _has_bit(2);
}
inline void PathPlanningRequestMessage::clear_gotoangle() {
  gotoangle_ = 0;
  _clear_bit(2);
}
inline float PathPlanningRequestMessage::gotoangle() const {
  return gotoangle_;
}
inline void PathPlanningRequestMessage::set_gotoangle(float value) {
  _set_bit(2);
  gotoangle_ = value;
}

// -------------------------------------------------------------------

// PathPlanningResultMessage

// required float moveToX = 1 [default = 0];
inline bool PathPlanningResultMessage::has_movetox() const {
  return _has_bit(0);
}
inline void PathPlanningResultMessage::clear_movetox() {
  movetox_ = 0;
  _clear_bit(0);
}
inline float PathPlanningResultMessage::movetox() const {
  return movetox_;
}
inline void PathPlanningResultMessage::set_movetox(float value) {
  _set_bit(0);
  movetox_ = value;
}

// required float moveToY = 2 [default = 0];
inline bool PathPlanningResultMessage::has_movetoy() const {
  return _has_bit(1);
}
inline void PathPlanningResultMessage::clear_movetoy() {
  movetoy_ = 0;
  _clear_bit(1);
}
inline float PathPlanningResultMessage::movetoy() const {
  return movetoy_;
}
inline void PathPlanningResultMessage::set_movetoy(float value) {
  _set_bit(1);
  movetoy_ = value;
}

// required float moveToAngle = 3 [default = 0];
inline bool PathPlanningResultMessage::has_movetoangle() const {
  return _has_bit(2);
}
inline void PathPlanningResultMessage::clear_movetoangle() {
  movetoangle_ = 0;
  _clear_bit(2);
}
inline float PathPlanningResultMessage::movetoangle() const {
  return movetoangle_;
}
inline void PathPlanningResultMessage::set_movetoangle(float value) {
  _set_bit(2);
  movetoangle_ = value;
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ObstacleAvoidanceMessage_2eproto__INCLUDED
