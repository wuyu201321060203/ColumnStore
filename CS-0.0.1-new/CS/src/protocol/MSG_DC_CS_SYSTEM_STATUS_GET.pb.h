// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MSG_DC_CS_SYSTEM_STATUS_GET.proto

#ifndef PROTOBUF_MSG_5fDC_5fCS_5fSYSTEM_5fSTATUS_5fGET_2eproto__INCLUDED
#define PROTOBUF_MSG_5fDC_5fCS_5fSYSTEM_5fSTATUS_5fGET_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2004001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
#include "common.pb.h"
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_MSG_5fDC_5fCS_5fSYSTEM_5fSTATUS_5fGET_2eproto();
void protobuf_AssignDesc_MSG_5fDC_5fCS_5fSYSTEM_5fSTATUS_5fGET_2eproto();
void protobuf_ShutdownFile_MSG_5fDC_5fCS_5fSYSTEM_5fSTATUS_5fGET_2eproto();

class MSG_DC_CS_SYSTEM_STATUS_GET;
class MSG_CS_DC_SYSTEM_STATUS_GET_ACK;

// ===================================================================

class MSG_DC_CS_SYSTEM_STATUS_GET : public ::google::protobuf::Message {
 public:
  MSG_DC_CS_SYSTEM_STATUS_GET();
  virtual ~MSG_DC_CS_SYSTEM_STATUS_GET();
  
  MSG_DC_CS_SYSTEM_STATUS_GET(const MSG_DC_CS_SYSTEM_STATUS_GET& from);
  
  inline MSG_DC_CS_SYSTEM_STATUS_GET& operator=(const MSG_DC_CS_SYSTEM_STATUS_GET& from) {
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
  static const MSG_DC_CS_SYSTEM_STATUS_GET& default_instance();
  
  void Swap(MSG_DC_CS_SYSTEM_STATUS_GET* other);
  
  // implements Message ----------------------------------------------
  
  MSG_DC_CS_SYSTEM_STATUS_GET* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MSG_DC_CS_SYSTEM_STATUS_GET& from);
  void MergeFrom(const MSG_DC_CS_SYSTEM_STATUS_GET& from);
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
  
  // @@protoc_insertion_point(class_scope:MSG_DC_CS_SYSTEM_STATUS_GET)
 private:
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[1];
  
  friend void  protobuf_AddDesc_MSG_5fDC_5fCS_5fSYSTEM_5fSTATUS_5fGET_2eproto();
  friend void protobuf_AssignDesc_MSG_5fDC_5fCS_5fSYSTEM_5fSTATUS_5fGET_2eproto();
  friend void protobuf_ShutdownFile_MSG_5fDC_5fCS_5fSYSTEM_5fSTATUS_5fGET_2eproto();
  
  void InitAsDefaultInstance();
  static MSG_DC_CS_SYSTEM_STATUS_GET* default_instance_;
};
// -------------------------------------------------------------------

class MSG_CS_DC_SYSTEM_STATUS_GET_ACK : public ::google::protobuf::Message {
 public:
  MSG_CS_DC_SYSTEM_STATUS_GET_ACK();
  virtual ~MSG_CS_DC_SYSTEM_STATUS_GET_ACK();
  
  MSG_CS_DC_SYSTEM_STATUS_GET_ACK(const MSG_CS_DC_SYSTEM_STATUS_GET_ACK& from);
  
  inline MSG_CS_DC_SYSTEM_STATUS_GET_ACK& operator=(const MSG_CS_DC_SYSTEM_STATUS_GET_ACK& from) {
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
  static const MSG_CS_DC_SYSTEM_STATUS_GET_ACK& default_instance();
  
  void Swap(MSG_CS_DC_SYSTEM_STATUS_GET_ACK* other);
  
  // implements Message ----------------------------------------------
  
  MSG_CS_DC_SYSTEM_STATUS_GET_ACK* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MSG_CS_DC_SYSTEM_STATUS_GET_ACK& from);
  void MergeFrom(const MSG_CS_DC_SYSTEM_STATUS_GET_ACK& from);
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
  
  // required int32 statusCode = 1;
  inline bool has_statuscode() const;
  inline void clear_statuscode();
  static const int kStatusCodeFieldNumber = 1;
  inline ::google::protobuf::int32 statuscode() const;
  inline void set_statuscode(::google::protobuf::int32 value);
  
  // required .SINGLE_NODE_INFO nodeSysInfo = 2;
  inline bool has_nodesysinfo() const;
  inline void clear_nodesysinfo();
  static const int kNodeSysInfoFieldNumber = 2;
  inline const ::SINGLE_NODE_INFO& nodesysinfo() const;
  inline ::SINGLE_NODE_INFO* mutable_nodesysinfo();
  inline ::SINGLE_NODE_INFO* release_nodesysinfo();
  
  // @@protoc_insertion_point(class_scope:MSG_CS_DC_SYSTEM_STATUS_GET_ACK)
 private:
  inline void set_has_statuscode();
  inline void clear_has_statuscode();
  inline void set_has_nodesysinfo();
  inline void clear_has_nodesysinfo();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::SINGLE_NODE_INFO* nodesysinfo_;
  ::google::protobuf::int32 statuscode_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];
  
  friend void  protobuf_AddDesc_MSG_5fDC_5fCS_5fSYSTEM_5fSTATUS_5fGET_2eproto();
  friend void protobuf_AssignDesc_MSG_5fDC_5fCS_5fSYSTEM_5fSTATUS_5fGET_2eproto();
  friend void protobuf_ShutdownFile_MSG_5fDC_5fCS_5fSYSTEM_5fSTATUS_5fGET_2eproto();
  
  void InitAsDefaultInstance();
  static MSG_CS_DC_SYSTEM_STATUS_GET_ACK* default_instance_;
};
// ===================================================================


// ===================================================================

// MSG_DC_CS_SYSTEM_STATUS_GET

// -------------------------------------------------------------------

// MSG_CS_DC_SYSTEM_STATUS_GET_ACK

// required int32 statusCode = 1;
inline bool MSG_CS_DC_SYSTEM_STATUS_GET_ACK::has_statuscode() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void MSG_CS_DC_SYSTEM_STATUS_GET_ACK::set_has_statuscode() {
  _has_bits_[0] |= 0x00000001u;
}
inline void MSG_CS_DC_SYSTEM_STATUS_GET_ACK::clear_has_statuscode() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void MSG_CS_DC_SYSTEM_STATUS_GET_ACK::clear_statuscode() {
  statuscode_ = 0;
  clear_has_statuscode();
}
inline ::google::protobuf::int32 MSG_CS_DC_SYSTEM_STATUS_GET_ACK::statuscode() const {
  return statuscode_;
}
inline void MSG_CS_DC_SYSTEM_STATUS_GET_ACK::set_statuscode(::google::protobuf::int32 value) {
  set_has_statuscode();
  statuscode_ = value;
}

// required .SINGLE_NODE_INFO nodeSysInfo = 2;
inline bool MSG_CS_DC_SYSTEM_STATUS_GET_ACK::has_nodesysinfo() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void MSG_CS_DC_SYSTEM_STATUS_GET_ACK::set_has_nodesysinfo() {
  _has_bits_[0] |= 0x00000002u;
}
inline void MSG_CS_DC_SYSTEM_STATUS_GET_ACK::clear_has_nodesysinfo() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void MSG_CS_DC_SYSTEM_STATUS_GET_ACK::clear_nodesysinfo() {
  if (nodesysinfo_ != NULL) nodesysinfo_->::SINGLE_NODE_INFO::Clear();
  clear_has_nodesysinfo();
}
inline const ::SINGLE_NODE_INFO& MSG_CS_DC_SYSTEM_STATUS_GET_ACK::nodesysinfo() const {
  return nodesysinfo_ != NULL ? *nodesysinfo_ : *default_instance_->nodesysinfo_;
}
inline ::SINGLE_NODE_INFO* MSG_CS_DC_SYSTEM_STATUS_GET_ACK::mutable_nodesysinfo() {
  set_has_nodesysinfo();
  if (nodesysinfo_ == NULL) nodesysinfo_ = new ::SINGLE_NODE_INFO;
  return nodesysinfo_;
}
inline ::SINGLE_NODE_INFO* MSG_CS_DC_SYSTEM_STATUS_GET_ACK::release_nodesysinfo() {
  clear_has_nodesysinfo();
  ::SINGLE_NODE_INFO* temp = nodesysinfo_;
  nodesysinfo_ = NULL;
  return temp;
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_MSG_5fDC_5fCS_5fSYSTEM_5fSTATUS_5fGET_2eproto__INCLUDED
