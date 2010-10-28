// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Kimage.proto

#ifndef PROTOBUF_Kimage_2eproto__INCLUDED
#define PROTOBUF_Kimage_2eproto__INCLUDED

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
void  protobuf_AddDesc_Kimage_2eproto();
void protobuf_AssignDesc_Kimage_2eproto();
void protobuf_ShutdownFile_Kimage_2eproto();

class KRawImage;
class KRawImageHeader;

// ===================================================================

class KRawImage : public ::google::protobuf::Message {
 public:
  KRawImage();
  virtual ~KRawImage();
  
  KRawImage(const KRawImage& from);
  
  inline KRawImage& operator=(const KRawImage& from) {
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
  static const KRawImage& default_instance();
  
  void Swap(KRawImage* other);
  
  // implements Message ----------------------------------------------
  
  KRawImage* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const KRawImage& from);
  void MergeFrom(const KRawImage& from);
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
  
  // required int32 bytes = 1 [default = -1];
  inline bool has_bytes() const;
  inline void clear_bytes();
  static const int kBytesFieldNumber = 1;
  inline ::google::protobuf::int32 bytes() const;
  inline void set_bytes(::google::protobuf::int32 value);
  
  // required int32 width = 2 [default = 0];
  inline bool has_width() const;
  inline void clear_width();
  static const int kWidthFieldNumber = 2;
  inline ::google::protobuf::int32 width() const;
  inline void set_width(::google::protobuf::int32 value);
  
  // required int32 height = 3 [default = 0];
  inline bool has_height() const;
  inline void clear_height();
  static const int kHeightFieldNumber = 3;
  inline ::google::protobuf::int32 height() const;
  inline void set_height(::google::protobuf::int32 value);
  
  // required int32 type = 4 [default = 4];
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 4;
  inline ::google::protobuf::int32 type() const;
  inline void set_type(::google::protobuf::int32 value);
  
  // required bytes ImageRawData = 5;
  inline bool has_imagerawdata() const;
  inline void clear_imagerawdata();
  static const int kImageRawDataFieldNumber = 5;
  inline const ::std::string& imagerawdata() const;
  inline void set_imagerawdata(const ::std::string& value);
  inline void set_imagerawdata(const char* value);
  inline void set_imagerawdata(const void* value, size_t size);
  inline ::std::string* mutable_imagerawdata();
  
  // @@protoc_insertion_point(class_scope:KRawImage)
 private:
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  mutable int _cached_size_;
  
  ::google::protobuf::int32 bytes_;
  ::google::protobuf::int32 width_;
  ::google::protobuf::int32 height_;
  ::google::protobuf::int32 type_;
  ::std::string* imagerawdata_;
  static const ::std::string _default_imagerawdata_;
  friend void  protobuf_AddDesc_Kimage_2eproto();
  friend void protobuf_AssignDesc_Kimage_2eproto();
  friend void protobuf_ShutdownFile_Kimage_2eproto();
  
  ::google::protobuf::uint32 _has_bits_[(5 + 31) / 32];
  
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
  static KRawImage* default_instance_;
};
// -------------------------------------------------------------------

class KRawImageHeader : public ::google::protobuf::Message {
 public:
  KRawImageHeader();
  virtual ~KRawImageHeader();
  
  KRawImageHeader(const KRawImageHeader& from);
  
  inline KRawImageHeader& operator=(const KRawImageHeader& from) {
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
  static const KRawImageHeader& default_instance();
  
  void Swap(KRawImageHeader* other);
  
  // implements Message ----------------------------------------------
  
  KRawImageHeader* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const KRawImageHeader& from);
  void MergeFrom(const KRawImageHeader& from);
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
  
  // required int32 bytes = 1 [default = -1];
  inline bool has_bytes() const;
  inline void clear_bytes();
  static const int kBytesFieldNumber = 1;
  inline ::google::protobuf::int32 bytes() const;
  inline void set_bytes(::google::protobuf::int32 value);
  
  // required int32 width = 2 [default = 0];
  inline bool has_width() const;
  inline void clear_width();
  static const int kWidthFieldNumber = 2;
  inline ::google::protobuf::int32 width() const;
  inline void set_width(::google::protobuf::int32 value);
  
  // required int32 height = 3 [default = 0];
  inline bool has_height() const;
  inline void clear_height();
  static const int kHeightFieldNumber = 3;
  inline ::google::protobuf::int32 height() const;
  inline void set_height(::google::protobuf::int32 value);
  
  // required int32 type = 4 [default = 4];
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 4;
  inline ::google::protobuf::int32 type() const;
  inline void set_type(::google::protobuf::int32 value);
  
  // @@protoc_insertion_point(class_scope:KRawImageHeader)
 private:
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  mutable int _cached_size_;
  
  ::google::protobuf::int32 bytes_;
  ::google::protobuf::int32 width_;
  ::google::protobuf::int32 height_;
  ::google::protobuf::int32 type_;
  friend void  protobuf_AddDesc_Kimage_2eproto();
  friend void protobuf_AssignDesc_Kimage_2eproto();
  friend void protobuf_ShutdownFile_Kimage_2eproto();
  
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];
  
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
  static KRawImageHeader* default_instance_;
};
// ===================================================================


// ===================================================================

// KRawImage

// required int32 bytes = 1 [default = -1];
inline bool KRawImage::has_bytes() const {
  return _has_bit(0);
}
inline void KRawImage::clear_bytes() {
  bytes_ = -1;
  _clear_bit(0);
}
inline ::google::protobuf::int32 KRawImage::bytes() const {
  return bytes_;
}
inline void KRawImage::set_bytes(::google::protobuf::int32 value) {
  _set_bit(0);
  bytes_ = value;
}

// required int32 width = 2 [default = 0];
inline bool KRawImage::has_width() const {
  return _has_bit(1);
}
inline void KRawImage::clear_width() {
  width_ = 0;
  _clear_bit(1);
}
inline ::google::protobuf::int32 KRawImage::width() const {
  return width_;
}
inline void KRawImage::set_width(::google::protobuf::int32 value) {
  _set_bit(1);
  width_ = value;
}

// required int32 height = 3 [default = 0];
inline bool KRawImage::has_height() const {
  return _has_bit(2);
}
inline void KRawImage::clear_height() {
  height_ = 0;
  _clear_bit(2);
}
inline ::google::protobuf::int32 KRawImage::height() const {
  return height_;
}
inline void KRawImage::set_height(::google::protobuf::int32 value) {
  _set_bit(2);
  height_ = value;
}

// required int32 type = 4 [default = 4];
inline bool KRawImage::has_type() const {
  return _has_bit(3);
}
inline void KRawImage::clear_type() {
  type_ = 4;
  _clear_bit(3);
}
inline ::google::protobuf::int32 KRawImage::type() const {
  return type_;
}
inline void KRawImage::set_type(::google::protobuf::int32 value) {
  _set_bit(3);
  type_ = value;
}

// required bytes ImageRawData = 5;
inline bool KRawImage::has_imagerawdata() const {
  return _has_bit(4);
}
inline void KRawImage::clear_imagerawdata() {
  if (imagerawdata_ != &_default_imagerawdata_) {
    imagerawdata_->clear();
  }
  _clear_bit(4);
}
inline const ::std::string& KRawImage::imagerawdata() const {
  return *imagerawdata_;
}
inline void KRawImage::set_imagerawdata(const ::std::string& value) {
  _set_bit(4);
  if (imagerawdata_ == &_default_imagerawdata_) {
    imagerawdata_ = new ::std::string;
  }
  imagerawdata_->assign(value);
}
inline void KRawImage::set_imagerawdata(const char* value) {
  _set_bit(4);
  if (imagerawdata_ == &_default_imagerawdata_) {
    imagerawdata_ = new ::std::string;
  }
  imagerawdata_->assign(value);
}
inline void KRawImage::set_imagerawdata(const void* value, size_t size) {
  _set_bit(4);
  if (imagerawdata_ == &_default_imagerawdata_) {
    imagerawdata_ = new ::std::string;
  }
  imagerawdata_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* KRawImage::mutable_imagerawdata() {
  _set_bit(4);
  if (imagerawdata_ == &_default_imagerawdata_) {
    imagerawdata_ = new ::std::string;
  }
  return imagerawdata_;
}

// -------------------------------------------------------------------

// KRawImageHeader

// required int32 bytes = 1 [default = -1];
inline bool KRawImageHeader::has_bytes() const {
  return _has_bit(0);
}
inline void KRawImageHeader::clear_bytes() {
  bytes_ = -1;
  _clear_bit(0);
}
inline ::google::protobuf::int32 KRawImageHeader::bytes() const {
  return bytes_;
}
inline void KRawImageHeader::set_bytes(::google::protobuf::int32 value) {
  _set_bit(0);
  bytes_ = value;
}

// required int32 width = 2 [default = 0];
inline bool KRawImageHeader::has_width() const {
  return _has_bit(1);
}
inline void KRawImageHeader::clear_width() {
  width_ = 0;
  _clear_bit(1);
}
inline ::google::protobuf::int32 KRawImageHeader::width() const {
  return width_;
}
inline void KRawImageHeader::set_width(::google::protobuf::int32 value) {
  _set_bit(1);
  width_ = value;
}

// required int32 height = 3 [default = 0];
inline bool KRawImageHeader::has_height() const {
  return _has_bit(2);
}
inline void KRawImageHeader::clear_height() {
  height_ = 0;
  _clear_bit(2);
}
inline ::google::protobuf::int32 KRawImageHeader::height() const {
  return height_;
}
inline void KRawImageHeader::set_height(::google::protobuf::int32 value) {
  _set_bit(2);
  height_ = value;
}

// required int32 type = 4 [default = 4];
inline bool KRawImageHeader::has_type() const {
  return _has_bit(3);
}
inline void KRawImageHeader::clear_type() {
  type_ = 4;
  _clear_bit(3);
}
inline ::google::protobuf::int32 KRawImageHeader::type() const {
  return type_;
}
inline void KRawImageHeader::set_type(::google::protobuf::int32 value) {
  _set_bit(3);
  type_ = value;
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Kimage_2eproto__INCLUDED