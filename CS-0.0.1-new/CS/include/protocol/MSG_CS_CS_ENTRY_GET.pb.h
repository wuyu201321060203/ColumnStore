// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MSG_CS_CS_ENTRY_GET.proto

#ifndef PROTOBUF_MSG_5fCS_5fCS_5fENTRY_5fGET_2eproto__INCLUDED
#define PROTOBUF_MSG_5fCS_5fCS_5fENTRY_5fGET_2eproto__INCLUDED

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
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_MSG_5fCS_5fCS_5fENTRY_5fGET_2eproto();
void protobuf_AssignDesc_MSG_5fCS_5fCS_5fENTRY_5fGET_2eproto();
void protobuf_ShutdownFile_MSG_5fCS_5fCS_5fENTRY_5fGET_2eproto();

class MSG_CS_CS_ENTRY_GET;
class MSG_CS_CS_ENTRY_GET_ACK;

// ===================================================================

class MSG_CS_CS_ENTRY_GET : public ::google::protobuf::Message {
 public:
  MSG_CS_CS_ENTRY_GET();
  virtual ~MSG_CS_CS_ENTRY_GET();
  
  MSG_CS_CS_ENTRY_GET(const MSG_CS_CS_ENTRY_GET& from);
  
  inline MSG_CS_CS_ENTRY_GET& operator=(const MSG_CS_CS_ENTRY_GET& from) {
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
  static const MSG_CS_CS_ENTRY_GET& default_instance();
  
  void Swap(MSG_CS_CS_ENTRY_GET* other);
  
  // implements Message ----------------------------------------------
  
  MSG_CS_CS_ENTRY_GET* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MSG_CS_CS_ENTRY_GET& from);
  void MergeFrom(const MSG_CS_CS_ENTRY_GET& from);
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
  
  // optional uint32 dbID = 1;
  inline bool has_dbid() const;
  inline void clear_dbid();
  static const int kDbIDFieldNumber = 1;
  inline ::google::protobuf::uint32 dbid() const;
  inline void set_dbid(::google::protobuf::uint32 value);
  
  // optional string tableName = 2;
  inline bool has_tablename() const;
  inline void clear_tablename();
  static const int kTableNameFieldNumber = 2;
  inline const ::std::string& tablename() const;
  inline void set_tablename(const ::std::string& value);
  inline void set_tablename(const char* value);
  inline void set_tablename(const char* value, size_t size);
  inline ::std::string* mutable_tablename();
  inline ::std::string* release_tablename();
  
  // optional string columnName = 3;
  inline bool has_columnname() const;
  inline void clear_columnname();
  static const int kColumnNameFieldNumber = 3;
  inline const ::std::string& columnname() const;
  inline void set_columnname(const ::std::string& value);
  inline void set_columnname(const char* value);
  inline void set_columnname(const char* value, size_t size);
  inline ::std::string* mutable_columnname();
  inline ::std::string* release_columnname();
  
  // repeated uint64 rowKeys = 4;
  inline int rowkeys_size() const;
  inline void clear_rowkeys();
  static const int kRowKeysFieldNumber = 4;
  inline ::google::protobuf::uint64 rowkeys(int index) const;
  inline void set_rowkeys(int index, ::google::protobuf::uint64 value);
  inline void add_rowkeys(::google::protobuf::uint64 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >&
      rowkeys() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >*
      mutable_rowkeys();
  
  // @@protoc_insertion_point(class_scope:MSG_CS_CS_ENTRY_GET)
 private:
  inline void set_has_dbid();
  inline void clear_has_dbid();
  inline void set_has_tablename();
  inline void clear_has_tablename();
  inline void set_has_columnname();
  inline void clear_has_columnname();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::std::string* tablename_;
  ::std::string* columnname_;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint64 > rowkeys_;
  ::google::protobuf::uint32 dbid_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];
  
  friend void  protobuf_AddDesc_MSG_5fCS_5fCS_5fENTRY_5fGET_2eproto();
  friend void protobuf_AssignDesc_MSG_5fCS_5fCS_5fENTRY_5fGET_2eproto();
  friend void protobuf_ShutdownFile_MSG_5fCS_5fCS_5fENTRY_5fGET_2eproto();
  
  void InitAsDefaultInstance();
  static MSG_CS_CS_ENTRY_GET* default_instance_;
};
// -------------------------------------------------------------------

class MSG_CS_CS_ENTRY_GET_ACK : public ::google::protobuf::Message {
 public:
  MSG_CS_CS_ENTRY_GET_ACK();
  virtual ~MSG_CS_CS_ENTRY_GET_ACK();
  
  MSG_CS_CS_ENTRY_GET_ACK(const MSG_CS_CS_ENTRY_GET_ACK& from);
  
  inline MSG_CS_CS_ENTRY_GET_ACK& operator=(const MSG_CS_CS_ENTRY_GET_ACK& from) {
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
  static const MSG_CS_CS_ENTRY_GET_ACK& default_instance();
  
  void Swap(MSG_CS_CS_ENTRY_GET_ACK* other);
  
  // implements Message ----------------------------------------------
  
  MSG_CS_CS_ENTRY_GET_ACK* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MSG_CS_CS_ENTRY_GET_ACK& from);
  void MergeFrom(const MSG_CS_CS_ENTRY_GET_ACK& from);
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
  
  // optional int32 statusCode = 1;
  inline bool has_statuscode() const;
  inline void clear_statuscode();
  static const int kStatusCodeFieldNumber = 1;
  inline ::google::protobuf::int32 statuscode() const;
  inline void set_statuscode(::google::protobuf::int32 value);
  
  // optional uint32 dbID = 2;
  inline bool has_dbid() const;
  inline void clear_dbid();
  static const int kDbIDFieldNumber = 2;
  inline ::google::protobuf::uint32 dbid() const;
  inline void set_dbid(::google::protobuf::uint32 value);
  
  // optional string tableName = 3;
  inline bool has_tablename() const;
  inline void clear_tablename();
  static const int kTableNameFieldNumber = 3;
  inline const ::std::string& tablename() const;
  inline void set_tablename(const ::std::string& value);
  inline void set_tablename(const char* value);
  inline void set_tablename(const char* value, size_t size);
  inline ::std::string* mutable_tablename();
  inline ::std::string* release_tablename();
  
  // optional string columnName = 4;
  inline bool has_columnname() const;
  inline void clear_columnname();
  static const int kColumnNameFieldNumber = 4;
  inline const ::std::string& columnname() const;
  inline void set_columnname(const ::std::string& value);
  inline void set_columnname(const char* value);
  inline void set_columnname(const char* value, size_t size);
  inline ::std::string* mutable_columnname();
  inline ::std::string* release_columnname();
  
  // repeated uint32 entryList = 5;
  inline int entrylist_size() const;
  inline void clear_entrylist();
  static const int kEntryListFieldNumber = 5;
  inline ::google::protobuf::uint32 entrylist(int index) const;
  inline void set_entrylist(int index, ::google::protobuf::uint32 value);
  inline void add_entrylist(::google::protobuf::uint32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >&
      entrylist() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >*
      mutable_entrylist();
  
  // @@protoc_insertion_point(class_scope:MSG_CS_CS_ENTRY_GET_ACK)
 private:
  inline void set_has_statuscode();
  inline void clear_has_statuscode();
  inline void set_has_dbid();
  inline void clear_has_dbid();
  inline void set_has_tablename();
  inline void clear_has_tablename();
  inline void set_has_columnname();
  inline void clear_has_columnname();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::google::protobuf::int32 statuscode_;
  ::google::protobuf::uint32 dbid_;
  ::std::string* tablename_;
  ::std::string* columnname_;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint32 > entrylist_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(5 + 31) / 32];
  
  friend void  protobuf_AddDesc_MSG_5fCS_5fCS_5fENTRY_5fGET_2eproto();
  friend void protobuf_AssignDesc_MSG_5fCS_5fCS_5fENTRY_5fGET_2eproto();
  friend void protobuf_ShutdownFile_MSG_5fCS_5fCS_5fENTRY_5fGET_2eproto();
  
  void InitAsDefaultInstance();
  static MSG_CS_CS_ENTRY_GET_ACK* default_instance_;
};
// ===================================================================


// ===================================================================

// MSG_CS_CS_ENTRY_GET

// optional uint32 dbID = 1;
inline bool MSG_CS_CS_ENTRY_GET::has_dbid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void MSG_CS_CS_ENTRY_GET::set_has_dbid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void MSG_CS_CS_ENTRY_GET::clear_has_dbid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void MSG_CS_CS_ENTRY_GET::clear_dbid() {
  dbid_ = 0u;
  clear_has_dbid();
}
inline ::google::protobuf::uint32 MSG_CS_CS_ENTRY_GET::dbid() const {
  return dbid_;
}
inline void MSG_CS_CS_ENTRY_GET::set_dbid(::google::protobuf::uint32 value) {
  set_has_dbid();
  dbid_ = value;
}

// optional string tableName = 2;
inline bool MSG_CS_CS_ENTRY_GET::has_tablename() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void MSG_CS_CS_ENTRY_GET::set_has_tablename() {
  _has_bits_[0] |= 0x00000002u;
}
inline void MSG_CS_CS_ENTRY_GET::clear_has_tablename() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void MSG_CS_CS_ENTRY_GET::clear_tablename() {
  if (tablename_ != &::google::protobuf::internal::kEmptyString) {
    tablename_->clear();
  }
  clear_has_tablename();
}
inline const ::std::string& MSG_CS_CS_ENTRY_GET::tablename() const {
  return *tablename_;
}
inline void MSG_CS_CS_ENTRY_GET::set_tablename(const ::std::string& value) {
  set_has_tablename();
  if (tablename_ == &::google::protobuf::internal::kEmptyString) {
    tablename_ = new ::std::string;
  }
  tablename_->assign(value);
}
inline void MSG_CS_CS_ENTRY_GET::set_tablename(const char* value) {
  set_has_tablename();
  if (tablename_ == &::google::protobuf::internal::kEmptyString) {
    tablename_ = new ::std::string;
  }
  tablename_->assign(value);
}
inline void MSG_CS_CS_ENTRY_GET::set_tablename(const char* value, size_t size) {
  set_has_tablename();
  if (tablename_ == &::google::protobuf::internal::kEmptyString) {
    tablename_ = new ::std::string;
  }
  tablename_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* MSG_CS_CS_ENTRY_GET::mutable_tablename() {
  set_has_tablename();
  if (tablename_ == &::google::protobuf::internal::kEmptyString) {
    tablename_ = new ::std::string;
  }
  return tablename_;
}
inline ::std::string* MSG_CS_CS_ENTRY_GET::release_tablename() {
  clear_has_tablename();
  if (tablename_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = tablename_;
    tablename_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional string columnName = 3;
inline bool MSG_CS_CS_ENTRY_GET::has_columnname() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void MSG_CS_CS_ENTRY_GET::set_has_columnname() {
  _has_bits_[0] |= 0x00000004u;
}
inline void MSG_CS_CS_ENTRY_GET::clear_has_columnname() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void MSG_CS_CS_ENTRY_GET::clear_columnname() {
  if (columnname_ != &::google::protobuf::internal::kEmptyString) {
    columnname_->clear();
  }
  clear_has_columnname();
}
inline const ::std::string& MSG_CS_CS_ENTRY_GET::columnname() const {
  return *columnname_;
}
inline void MSG_CS_CS_ENTRY_GET::set_columnname(const ::std::string& value) {
  set_has_columnname();
  if (columnname_ == &::google::protobuf::internal::kEmptyString) {
    columnname_ = new ::std::string;
  }
  columnname_->assign(value);
}
inline void MSG_CS_CS_ENTRY_GET::set_columnname(const char* value) {
  set_has_columnname();
  if (columnname_ == &::google::protobuf::internal::kEmptyString) {
    columnname_ = new ::std::string;
  }
  columnname_->assign(value);
}
inline void MSG_CS_CS_ENTRY_GET::set_columnname(const char* value, size_t size) {
  set_has_columnname();
  if (columnname_ == &::google::protobuf::internal::kEmptyString) {
    columnname_ = new ::std::string;
  }
  columnname_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* MSG_CS_CS_ENTRY_GET::mutable_columnname() {
  set_has_columnname();
  if (columnname_ == &::google::protobuf::internal::kEmptyString) {
    columnname_ = new ::std::string;
  }
  return columnname_;
}
inline ::std::string* MSG_CS_CS_ENTRY_GET::release_columnname() {
  clear_has_columnname();
  if (columnname_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = columnname_;
    columnname_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// repeated uint64 rowKeys = 4;
inline int MSG_CS_CS_ENTRY_GET::rowkeys_size() const {
  return rowkeys_.size();
}
inline void MSG_CS_CS_ENTRY_GET::clear_rowkeys() {
  rowkeys_.Clear();
}
inline ::google::protobuf::uint64 MSG_CS_CS_ENTRY_GET::rowkeys(int index) const {
  return rowkeys_.Get(index);
}
inline void MSG_CS_CS_ENTRY_GET::set_rowkeys(int index, ::google::protobuf::uint64 value) {
  rowkeys_.Set(index, value);
}
inline void MSG_CS_CS_ENTRY_GET::add_rowkeys(::google::protobuf::uint64 value) {
  rowkeys_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >&
MSG_CS_CS_ENTRY_GET::rowkeys() const {
  return rowkeys_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >*
MSG_CS_CS_ENTRY_GET::mutable_rowkeys() {
  return &rowkeys_;
}

// -------------------------------------------------------------------

// MSG_CS_CS_ENTRY_GET_ACK

// optional int32 statusCode = 1;
inline bool MSG_CS_CS_ENTRY_GET_ACK::has_statuscode() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void MSG_CS_CS_ENTRY_GET_ACK::set_has_statuscode() {
  _has_bits_[0] |= 0x00000001u;
}
inline void MSG_CS_CS_ENTRY_GET_ACK::clear_has_statuscode() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void MSG_CS_CS_ENTRY_GET_ACK::clear_statuscode() {
  statuscode_ = 0;
  clear_has_statuscode();
}
inline ::google::protobuf::int32 MSG_CS_CS_ENTRY_GET_ACK::statuscode() const {
  return statuscode_;
}
inline void MSG_CS_CS_ENTRY_GET_ACK::set_statuscode(::google::protobuf::int32 value) {
  set_has_statuscode();
  statuscode_ = value;
}

// optional uint32 dbID = 2;
inline bool MSG_CS_CS_ENTRY_GET_ACK::has_dbid() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void MSG_CS_CS_ENTRY_GET_ACK::set_has_dbid() {
  _has_bits_[0] |= 0x00000002u;
}
inline void MSG_CS_CS_ENTRY_GET_ACK::clear_has_dbid() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void MSG_CS_CS_ENTRY_GET_ACK::clear_dbid() {
  dbid_ = 0u;
  clear_has_dbid();
}
inline ::google::protobuf::uint32 MSG_CS_CS_ENTRY_GET_ACK::dbid() const {
  return dbid_;
}
inline void MSG_CS_CS_ENTRY_GET_ACK::set_dbid(::google::protobuf::uint32 value) {
  set_has_dbid();
  dbid_ = value;
}

// optional string tableName = 3;
inline bool MSG_CS_CS_ENTRY_GET_ACK::has_tablename() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void MSG_CS_CS_ENTRY_GET_ACK::set_has_tablename() {
  _has_bits_[0] |= 0x00000004u;
}
inline void MSG_CS_CS_ENTRY_GET_ACK::clear_has_tablename() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void MSG_CS_CS_ENTRY_GET_ACK::clear_tablename() {
  if (tablename_ != &::google::protobuf::internal::kEmptyString) {
    tablename_->clear();
  }
  clear_has_tablename();
}
inline const ::std::string& MSG_CS_CS_ENTRY_GET_ACK::tablename() const {
  return *tablename_;
}
inline void MSG_CS_CS_ENTRY_GET_ACK::set_tablename(const ::std::string& value) {
  set_has_tablename();
  if (tablename_ == &::google::protobuf::internal::kEmptyString) {
    tablename_ = new ::std::string;
  }
  tablename_->assign(value);
}
inline void MSG_CS_CS_ENTRY_GET_ACK::set_tablename(const char* value) {
  set_has_tablename();
  if (tablename_ == &::google::protobuf::internal::kEmptyString) {
    tablename_ = new ::std::string;
  }
  tablename_->assign(value);
}
inline void MSG_CS_CS_ENTRY_GET_ACK::set_tablename(const char* value, size_t size) {
  set_has_tablename();
  if (tablename_ == &::google::protobuf::internal::kEmptyString) {
    tablename_ = new ::std::string;
  }
  tablename_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* MSG_CS_CS_ENTRY_GET_ACK::mutable_tablename() {
  set_has_tablename();
  if (tablename_ == &::google::protobuf::internal::kEmptyString) {
    tablename_ = new ::std::string;
  }
  return tablename_;
}
inline ::std::string* MSG_CS_CS_ENTRY_GET_ACK::release_tablename() {
  clear_has_tablename();
  if (tablename_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = tablename_;
    tablename_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional string columnName = 4;
inline bool MSG_CS_CS_ENTRY_GET_ACK::has_columnname() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void MSG_CS_CS_ENTRY_GET_ACK::set_has_columnname() {
  _has_bits_[0] |= 0x00000008u;
}
inline void MSG_CS_CS_ENTRY_GET_ACK::clear_has_columnname() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void MSG_CS_CS_ENTRY_GET_ACK::clear_columnname() {
  if (columnname_ != &::google::protobuf::internal::kEmptyString) {
    columnname_->clear();
  }
  clear_has_columnname();
}
inline const ::std::string& MSG_CS_CS_ENTRY_GET_ACK::columnname() const {
  return *columnname_;
}
inline void MSG_CS_CS_ENTRY_GET_ACK::set_columnname(const ::std::string& value) {
  set_has_columnname();
  if (columnname_ == &::google::protobuf::internal::kEmptyString) {
    columnname_ = new ::std::string;
  }
  columnname_->assign(value);
}
inline void MSG_CS_CS_ENTRY_GET_ACK::set_columnname(const char* value) {
  set_has_columnname();
  if (columnname_ == &::google::protobuf::internal::kEmptyString) {
    columnname_ = new ::std::string;
  }
  columnname_->assign(value);
}
inline void MSG_CS_CS_ENTRY_GET_ACK::set_columnname(const char* value, size_t size) {
  set_has_columnname();
  if (columnname_ == &::google::protobuf::internal::kEmptyString) {
    columnname_ = new ::std::string;
  }
  columnname_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* MSG_CS_CS_ENTRY_GET_ACK::mutable_columnname() {
  set_has_columnname();
  if (columnname_ == &::google::protobuf::internal::kEmptyString) {
    columnname_ = new ::std::string;
  }
  return columnname_;
}
inline ::std::string* MSG_CS_CS_ENTRY_GET_ACK::release_columnname() {
  clear_has_columnname();
  if (columnname_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = columnname_;
    columnname_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// repeated uint32 entryList = 5;
inline int MSG_CS_CS_ENTRY_GET_ACK::entrylist_size() const {
  return entrylist_.size();
}
inline void MSG_CS_CS_ENTRY_GET_ACK::clear_entrylist() {
  entrylist_.Clear();
}
inline ::google::protobuf::uint32 MSG_CS_CS_ENTRY_GET_ACK::entrylist(int index) const {
  return entrylist_.Get(index);
}
inline void MSG_CS_CS_ENTRY_GET_ACK::set_entrylist(int index, ::google::protobuf::uint32 value) {
  entrylist_.Set(index, value);
}
inline void MSG_CS_CS_ENTRY_GET_ACK::add_entrylist(::google::protobuf::uint32 value) {
  entrylist_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >&
MSG_CS_CS_ENTRY_GET_ACK::entrylist() const {
  return entrylist_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >*
MSG_CS_CS_ENTRY_GET_ACK::mutable_entrylist() {
  return &entrylist_;
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_MSG_5fCS_5fCS_5fENTRY_5fGET_2eproto__INCLUDED