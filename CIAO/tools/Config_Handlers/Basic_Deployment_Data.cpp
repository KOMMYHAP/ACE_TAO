#include "Basic_Deployment_Data.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    // TCKind
    // 

    TCKind::Value TCKind::
    integral () const
    {
      return v_;
    }

    bool
    operator== (::CIAO::Config_Handlers::TCKind const& a, ::CIAO::Config_Handlers::TCKind const& b)
    {
      return a.v_ == b.v_;
    }

    bool
    operator!= (::CIAO::Config_Handlers::TCKind const& a, ::CIAO::Config_Handlers::TCKind const& b)
    {
      return a.v_ != b.v_;
    }

    TCKind::
    TCKind (TCKind::Value v)
    : v_ (v)
    {
    }

    // DataType
    // 

    DataType::
    DataType (::CIAO::Config_Handlers::TCKind const& kind__)
    : 
    ::XSCRT::Type (), 
    kind_ (new ::CIAO::Config_Handlers::TCKind (kind__)),
    regulator__ ()
    {
      kind_->container (this);
    }

    DataType::
    DataType (::CIAO::Config_Handlers::DataType const& s)
    :
    ::XSCRT::Type (),
    kind_ (new ::CIAO::Config_Handlers::TCKind (*s.kind_)),
    enum__ (s.enum__.get () ? new ::CIAO::Config_Handlers::EnumType (*s.enum__) : 0),
    regulator__ ()
    {
      kind_->container (this);
      if (enum__.get ()) enum__->container (this);
    }

    ::CIAO::Config_Handlers::DataType& DataType::
    operator= (::CIAO::Config_Handlers::DataType const& s)
    {
      kind (s.kind ());

      if (s.enum__.get ()) enum_ (*(s.enum__));
      else enum__ = ::std::auto_ptr< ::CIAO::Config_Handlers::EnumType > (0);

      return *this;
    }


    // DataType
    // 
    ::CIAO::Config_Handlers::TCKind const& DataType::
    kind () const
    {
      return *kind_;
    }

    void DataType::
    kind (::CIAO::Config_Handlers::TCKind const& e)
    {
      *kind_ = e;
    }

    // DataType
    // 
    bool DataType::
    enum_p () const
    {
      return enum__.get () != 0;
    }

    ::CIAO::Config_Handlers::EnumType const& DataType::
    enum_ () const
    {
      return *enum__;
    }

    void DataType::
    enum_ (::CIAO::Config_Handlers::EnumType const& e)
    {
      if (enum__.get ())
      {
        *enum__ = e;
      }

      else
      {
        enum__ = ::std::auto_ptr< ::CIAO::Config_Handlers::EnumType > (new ::CIAO::Config_Handlers::EnumType (e));
        enum__->container (this);
      }
    }


    // DataValue
    // 

    DataValue::
    DataValue ()
    : 
    ::XSCRT::Type (), 
    regulator__ ()
    {
    }

    DataValue::
    DataValue (::CIAO::Config_Handlers::DataValue const& s)
    :
    ::XSCRT::Type (),
    regulator__ ()
    {
      {
        for (short_const_iterator i (s.short_.begin ());i != s.short_.end ();++i) add_short (*i);
      }

      {
        for (long_const_iterator i (s.long_.begin ());i != s.long_.end ();++i) add_long (*i);
      }

      {
        for (ushort_const_iterator i (s.ushort_.begin ());i != s.ushort_.end ();++i) add_ushort (*i);
      }

      {
        for (ulong_const_iterator i (s.ulong_.begin ());i != s.ulong_.end ();++i) add_ulong (*i);
      }

      {
        for (float_const_iterator i (s.float_.begin ());i != s.float_.end ();++i) add_float (*i);
      }

      {
        for (double_const_iterator i (s.double_.begin ());i != s.double_.end ();++i) add_double (*i);
      }

      {
        for (boolean_const_iterator i (s.boolean_.begin ());i != s.boolean_.end ();++i) add_boolean (*i);
      }

      {
        for (octet_const_iterator i (s.octet_.begin ());i != s.octet_.end ();++i) add_octet (*i);
      }

      {
        for (enum_const_iterator i (s.enum_.begin ());i != s.enum_.end ();++i) add_enum (*i);
      }

      {
        for (string_const_iterator i (s.string_.begin ());i != s.string_.end ();++i) add_string (*i);
      }

      {
        for (longlong_const_iterator i (s.longlong_.begin ());i != s.longlong_.end ();++i) add_longlong (*i);
      }

      {
        for (ulonglong_const_iterator i (s.ulonglong_.begin ());i != s.ulonglong_.end ();++i) add_ulonglong (*i);
      }

      {
        for (longdouble_const_iterator i (s.longdouble_.begin ());i != s.longdouble_.end ();++i) add_longdouble (*i);
      }
    }

    ::CIAO::Config_Handlers::DataValue& DataValue::
    operator= (::CIAO::Config_Handlers::DataValue const& s)
    {
      short_.clear ();
      {
        for (short_const_iterator i (s.short_.begin ());i != s.short_.end ();++i) add_short (*i);
      }

      long_.clear ();
      {
        for (long_const_iterator i (s.long_.begin ());i != s.long_.end ();++i) add_long (*i);
      }

      ushort_.clear ();
      {
        for (ushort_const_iterator i (s.ushort_.begin ());i != s.ushort_.end ();++i) add_ushort (*i);
      }

      ulong_.clear ();
      {
        for (ulong_const_iterator i (s.ulong_.begin ());i != s.ulong_.end ();++i) add_ulong (*i);
      }

      float_.clear ();
      {
        for (float_const_iterator i (s.float_.begin ());i != s.float_.end ();++i) add_float (*i);
      }

      double_.clear ();
      {
        for (double_const_iterator i (s.double_.begin ());i != s.double_.end ();++i) add_double (*i);
      }

      boolean_.clear ();
      {
        for (boolean_const_iterator i (s.boolean_.begin ());i != s.boolean_.end ();++i) add_boolean (*i);
      }

      octet_.clear ();
      {
        for (octet_const_iterator i (s.octet_.begin ());i != s.octet_.end ();++i) add_octet (*i);
      }

      enum_.clear ();
      {
        for (enum_const_iterator i (s.enum_.begin ());i != s.enum_.end ();++i) add_enum (*i);
      }

      string_.clear ();
      {
        for (string_const_iterator i (s.string_.begin ());i != s.string_.end ();++i) add_string (*i);
      }

      longlong_.clear ();
      {
        for (longlong_const_iterator i (s.longlong_.begin ());i != s.longlong_.end ();++i) add_longlong (*i);
      }

      ulonglong_.clear ();
      {
        for (ulonglong_const_iterator i (s.ulonglong_.begin ());i != s.ulonglong_.end ();++i) add_ulonglong (*i);
      }

      longdouble_.clear ();
      {
        for (longdouble_const_iterator i (s.longdouble_.begin ());i != s.longdouble_.end ();++i) add_longdouble (*i);
      }

      return *this;
    }


    // DataValue
    // 
    DataValue::short_iterator DataValue::
    begin_short ()
    {
      return short_.begin ();
    }

    DataValue::short_iterator DataValue::
    end_short ()
    {
      return short_.end ();
    }

    DataValue::short_const_iterator DataValue::
    begin_short () const
    {
      return short_.begin ();
    }

    DataValue::short_const_iterator DataValue::
    end_short () const
    {
      return short_.end ();
    }

    void DataValue::
    add_short (::XMLSchema::short_ const& e)
    {
      short_.push_back (e);
    }

    size_t DataValue::
    count_short(void) const
    {
      return short_.size ();
    }

    // DataValue
    // 
    DataValue::long_iterator DataValue::
    begin_long ()
    {
      return long_.begin ();
    }

    DataValue::long_iterator DataValue::
    end_long ()
    {
      return long_.end ();
    }

    DataValue::long_const_iterator DataValue::
    begin_long () const
    {
      return long_.begin ();
    }

    DataValue::long_const_iterator DataValue::
    end_long () const
    {
      return long_.end ();
    }

    void DataValue::
    add_long (::XMLSchema::int_ const& e)
    {
      long_.push_back (e);
    }

    size_t DataValue::
    count_long(void) const
    {
      return long_.size ();
    }

    // DataValue
    // 
    DataValue::ushort_iterator DataValue::
    begin_ushort ()
    {
      return ushort_.begin ();
    }

    DataValue::ushort_iterator DataValue::
    end_ushort ()
    {
      return ushort_.end ();
    }

    DataValue::ushort_const_iterator DataValue::
    begin_ushort () const
    {
      return ushort_.begin ();
    }

    DataValue::ushort_const_iterator DataValue::
    end_ushort () const
    {
      return ushort_.end ();
    }

    void DataValue::
    add_ushort (::XMLSchema::unsignedShort const& e)
    {
      ushort_.push_back (e);
    }

    size_t DataValue::
    count_ushort(void) const
    {
      return ushort_.size ();
    }

    // DataValue
    // 
    DataValue::ulong_iterator DataValue::
    begin_ulong ()
    {
      return ulong_.begin ();
    }

    DataValue::ulong_iterator DataValue::
    end_ulong ()
    {
      return ulong_.end ();
    }

    DataValue::ulong_const_iterator DataValue::
    begin_ulong () const
    {
      return ulong_.begin ();
    }

    DataValue::ulong_const_iterator DataValue::
    end_ulong () const
    {
      return ulong_.end ();
    }

    void DataValue::
    add_ulong (::XMLSchema::unsignedInt const& e)
    {
      ulong_.push_back (e);
    }

    size_t DataValue::
    count_ulong(void) const
    {
      return ulong_.size ();
    }

    // DataValue
    // 
    DataValue::float_iterator DataValue::
    begin_float ()
    {
      return float_.begin ();
    }

    DataValue::float_iterator DataValue::
    end_float ()
    {
      return float_.end ();
    }

    DataValue::float_const_iterator DataValue::
    begin_float () const
    {
      return float_.begin ();
    }

    DataValue::float_const_iterator DataValue::
    end_float () const
    {
      return float_.end ();
    }

    void DataValue::
    add_float (::XMLSchema::float_ const& e)
    {
      float_.push_back (e);
    }

    size_t DataValue::
    count_float(void) const
    {
      return float_.size ();
    }

    // DataValue
    // 
    DataValue::double_iterator DataValue::
    begin_double ()
    {
      return double_.begin ();
    }

    DataValue::double_iterator DataValue::
    end_double ()
    {
      return double_.end ();
    }

    DataValue::double_const_iterator DataValue::
    begin_double () const
    {
      return double_.begin ();
    }

    DataValue::double_const_iterator DataValue::
    end_double () const
    {
      return double_.end ();
    }

    void DataValue::
    add_double (::XMLSchema::double_ const& e)
    {
      double_.push_back (e);
    }

    size_t DataValue::
    count_double(void) const
    {
      return double_.size ();
    }

    // DataValue
    // 
    DataValue::boolean_iterator DataValue::
    begin_boolean ()
    {
      return boolean_.begin ();
    }

    DataValue::boolean_iterator DataValue::
    end_boolean ()
    {
      return boolean_.end ();
    }

    DataValue::boolean_const_iterator DataValue::
    begin_boolean () const
    {
      return boolean_.begin ();
    }

    DataValue::boolean_const_iterator DataValue::
    end_boolean () const
    {
      return boolean_.end ();
    }

    void DataValue::
    add_boolean (::XMLSchema::boolean const& e)
    {
      boolean_.push_back (e);
    }

    size_t DataValue::
    count_boolean(void) const
    {
      return boolean_.size ();
    }

    // DataValue
    // 
    DataValue::octet_iterator DataValue::
    begin_octet ()
    {
      return octet_.begin ();
    }

    DataValue::octet_iterator DataValue::
    end_octet ()
    {
      return octet_.end ();
    }

    DataValue::octet_const_iterator DataValue::
    begin_octet () const
    {
      return octet_.begin ();
    }

    DataValue::octet_const_iterator DataValue::
    end_octet () const
    {
      return octet_.end ();
    }

    void DataValue::
    add_octet (::XMLSchema::unsignedByte const& e)
    {
      octet_.push_back (e);
    }

    size_t DataValue::
    count_octet(void) const
    {
      return octet_.size ();
    }

    // DataValue
    // 
    DataValue::enum_iterator DataValue::
    begin_enum ()
    {
      return enum_.begin ();
    }

    DataValue::enum_iterator DataValue::
    end_enum ()
    {
      return enum_.end ();
    }

    DataValue::enum_const_iterator DataValue::
    begin_enum () const
    {
      return enum_.begin ();
    }

    DataValue::enum_const_iterator DataValue::
    end_enum () const
    {
      return enum_.end ();
    }

    void DataValue::
    add_enum (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      enum_.push_back (e);
    }

    size_t DataValue::
    count_enum(void) const
    {
      return enum_.size ();
    }

    // DataValue
    // 
    DataValue::string_iterator DataValue::
    begin_string ()
    {
      return string_.begin ();
    }

    DataValue::string_iterator DataValue::
    end_string ()
    {
      return string_.end ();
    }

    DataValue::string_const_iterator DataValue::
    begin_string () const
    {
      return string_.begin ();
    }

    DataValue::string_const_iterator DataValue::
    end_string () const
    {
      return string_.end ();
    }

    void DataValue::
    add_string (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      string_.push_back (e);
    }

    size_t DataValue::
    count_string(void) const
    {
      return string_.size ();
    }

    // DataValue
    // 
    DataValue::longlong_iterator DataValue::
    begin_longlong ()
    {
      return longlong_.begin ();
    }

    DataValue::longlong_iterator DataValue::
    end_longlong ()
    {
      return longlong_.end ();
    }

    DataValue::longlong_const_iterator DataValue::
    begin_longlong () const
    {
      return longlong_.begin ();
    }

    DataValue::longlong_const_iterator DataValue::
    end_longlong () const
    {
      return longlong_.end ();
    }

    void DataValue::
    add_longlong (::XMLSchema::long_ const& e)
    {
      longlong_.push_back (e);
    }

    size_t DataValue::
    count_longlong(void) const
    {
      return longlong_.size ();
    }

    // DataValue
    // 
    DataValue::ulonglong_iterator DataValue::
    begin_ulonglong ()
    {
      return ulonglong_.begin ();
    }

    DataValue::ulonglong_iterator DataValue::
    end_ulonglong ()
    {
      return ulonglong_.end ();
    }

    DataValue::ulonglong_const_iterator DataValue::
    begin_ulonglong () const
    {
      return ulonglong_.begin ();
    }

    DataValue::ulonglong_const_iterator DataValue::
    end_ulonglong () const
    {
      return ulonglong_.end ();
    }

    void DataValue::
    add_ulonglong (::XMLSchema::unsignedLong const& e)
    {
      ulonglong_.push_back (e);
    }

    size_t DataValue::
    count_ulonglong(void) const
    {
      return ulonglong_.size ();
    }

    // DataValue
    // 
    DataValue::longdouble_iterator DataValue::
    begin_longdouble ()
    {
      return longdouble_.begin ();
    }

    DataValue::longdouble_iterator DataValue::
    end_longdouble ()
    {
      return longdouble_.end ();
    }

    DataValue::longdouble_const_iterator DataValue::
    begin_longdouble () const
    {
      return longdouble_.begin ();
    }

    DataValue::longdouble_const_iterator DataValue::
    end_longdouble () const
    {
      return longdouble_.end ();
    }

    void DataValue::
    add_longdouble (::XMLSchema::double_ const& e)
    {
      longdouble_.push_back (e);
    }

    size_t DataValue::
    count_longdouble(void) const
    {
      return longdouble_.size ();
    }


    // EnumType
    // 

    EnumType::
    EnumType (::XMLSchema::string< ACE_TCHAR > const& name__,
              ::XMLSchema::string< ACE_TCHAR > const& typeId__)
    : 
    ::XSCRT::Type (), 
    name_ (new ::XMLSchema::string< ACE_TCHAR > (name__)),
    typeId_ (new ::XMLSchema::string< ACE_TCHAR > (typeId__)),
    regulator__ ()
    {
      name_->container (this);
      typeId_->container (this);
    }

    EnumType::
    EnumType (::CIAO::Config_Handlers::EnumType const& s)
    :
    ::XSCRT::Type (),
    name_ (new ::XMLSchema::string< ACE_TCHAR > (*s.name_)),
    typeId_ (new ::XMLSchema::string< ACE_TCHAR > (*s.typeId_)),
    regulator__ ()
    {
      name_->container (this);
      typeId_->container (this);
      {
        for (member_const_iterator i (s.member_.begin ());i != s.member_.end ();++i) add_member (*i);
      }
    }

    ::CIAO::Config_Handlers::EnumType& EnumType::
    operator= (::CIAO::Config_Handlers::EnumType const& s)
    {
      name (s.name ());

      typeId (s.typeId ());

      member_.clear ();
      {
        for (member_const_iterator i (s.member_.begin ());i != s.member_.end ();++i) add_member (*i);
      }

      return *this;
    }


    // EnumType
    // 
    ::XMLSchema::string< ACE_TCHAR > const& EnumType::
    name () const
    {
      return *name_;
    }

    void EnumType::
    name (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *name_ = e;
    }

    // EnumType
    // 
    ::XMLSchema::string< ACE_TCHAR > const& EnumType::
    typeId () const
    {
      return *typeId_;
    }

    void EnumType::
    typeId (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *typeId_ = e;
    }

    // EnumType
    // 
    EnumType::member_iterator EnumType::
    begin_member ()
    {
      return member_.begin ();
    }

    EnumType::member_iterator EnumType::
    end_member ()
    {
      return member_.end ();
    }

    EnumType::member_const_iterator EnumType::
    begin_member () const
    {
      return member_.begin ();
    }

    EnumType::member_const_iterator EnumType::
    end_member () const
    {
      return member_.end ();
    }

    void EnumType::
    add_member (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      member_.push_back (e);
    }

    size_t EnumType::
    count_member(void) const
    {
      return member_.size ();
    }


    // Any
    // 

    Any::
    Any (::CIAO::Config_Handlers::DataType const& type__,
         ::CIAO::Config_Handlers::DataValue const& value__)
    : 
    ::XSCRT::Type (), 
    type_ (new ::CIAO::Config_Handlers::DataType (type__)),
    value_ (new ::CIAO::Config_Handlers::DataValue (value__)),
    regulator__ ()
    {
      type_->container (this);
      value_->container (this);
    }

    Any::
    Any (::CIAO::Config_Handlers::Any const& s)
    :
    ::XSCRT::Type (),
    type_ (new ::CIAO::Config_Handlers::DataType (*s.type_)),
    value_ (new ::CIAO::Config_Handlers::DataValue (*s.value_)),
    regulator__ ()
    {
      type_->container (this);
      value_->container (this);
    }

    ::CIAO::Config_Handlers::Any& Any::
    operator= (::CIAO::Config_Handlers::Any const& s)
    {
      type (s.type ());

      value (s.value ());

      return *this;
    }


    // Any
    // 
    ::CIAO::Config_Handlers::DataType const& Any::
    type () const
    {
      return *type_;
    }

    void Any::
    type (::CIAO::Config_Handlers::DataType const& e)
    {
      *type_ = e;
    }

    // Any
    // 
    ::CIAO::Config_Handlers::DataValue const& Any::
    value () const
    {
      return *value_;
    }

    void Any::
    value (::CIAO::Config_Handlers::DataValue const& e)
    {
      *value_ = e;
    }


    // Property
    // 

    Property::
    Property (::XMLSchema::string< ACE_TCHAR > const& name__,
              ::CIAO::Config_Handlers::Any const& value__)
    : 
    ::XSCRT::Type (), 
    name_ (new ::XMLSchema::string< ACE_TCHAR > (name__)),
    value_ (new ::CIAO::Config_Handlers::Any (value__)),
    regulator__ ()
    {
      name_->container (this);
      value_->container (this);
    }

    Property::
    Property (::CIAO::Config_Handlers::Property const& s)
    :
    ::XSCRT::Type (),
    name_ (new ::XMLSchema::string< ACE_TCHAR > (*s.name_)),
    value_ (new ::CIAO::Config_Handlers::Any (*s.value_)),
    regulator__ ()
    {
      name_->container (this);
      value_->container (this);
    }

    ::CIAO::Config_Handlers::Property& Property::
    operator= (::CIAO::Config_Handlers::Property const& s)
    {
      name (s.name ());

      value (s.value ());

      return *this;
    }


    // Property
    // 
    ::XMLSchema::string< ACE_TCHAR > const& Property::
    name () const
    {
      return *name_;
    }

    void Property::
    name (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *name_ = e;
    }

    // Property
    // 
    ::CIAO::Config_Handlers::Any const& Property::
    value () const
    {
      return *value_;
    }

    void Property::
    value (::CIAO::Config_Handlers::Any const& e)
    {
      *value_ = e;
    }


    // SatisfierPropertyKind
    // 

    SatisfierPropertyKind::Value SatisfierPropertyKind::
    integral () const
    {
      return v_;
    }

    bool
    operator== (::CIAO::Config_Handlers::SatisfierPropertyKind const& a, ::CIAO::Config_Handlers::SatisfierPropertyKind const& b)
    {
      return a.v_ == b.v_;
    }

    bool
    operator!= (::CIAO::Config_Handlers::SatisfierPropertyKind const& a, ::CIAO::Config_Handlers::SatisfierPropertyKind const& b)
    {
      return a.v_ != b.v_;
    }

    SatisfierPropertyKind::
    SatisfierPropertyKind (SatisfierPropertyKind::Value v)
    : v_ (v)
    {
    }

    // SatisfierProperty
    // 

    SatisfierProperty::
    SatisfierProperty (::XMLSchema::string< ACE_TCHAR > const& name__,
                       ::CIAO::Config_Handlers::SatisfierPropertyKind const& kind__,
                       ::XMLSchema::boolean const& dynamic__,
                       ::CIAO::Config_Handlers::Any const& value__)
    : 
    ::XSCRT::Type (), 
    name_ (new ::XMLSchema::string< ACE_TCHAR > (name__)),
    kind_ (new ::CIAO::Config_Handlers::SatisfierPropertyKind (kind__)),
    dynamic_ (new ::XMLSchema::boolean (dynamic__)),
    value_ (new ::CIAO::Config_Handlers::Any (value__)),
    regulator__ ()
    {
      name_->container (this);
      kind_->container (this);
      dynamic_->container (this);
      value_->container (this);
    }

    SatisfierProperty::
    SatisfierProperty (::CIAO::Config_Handlers::SatisfierProperty const& s)
    :
    ::XSCRT::Type (),
    name_ (new ::XMLSchema::string< ACE_TCHAR > (*s.name_)),
    kind_ (new ::CIAO::Config_Handlers::SatisfierPropertyKind (*s.kind_)),
    dynamic_ (new ::XMLSchema::boolean (*s.dynamic_)),
    value_ (new ::CIAO::Config_Handlers::Any (*s.value_)),
    regulator__ ()
    {
      name_->container (this);
      kind_->container (this);
      dynamic_->container (this);
      value_->container (this);
    }

    ::CIAO::Config_Handlers::SatisfierProperty& SatisfierProperty::
    operator= (::CIAO::Config_Handlers::SatisfierProperty const& s)
    {
      name (s.name ());

      kind (s.kind ());

      dynamic (s.dynamic ());

      value (s.value ());

      return *this;
    }


    // SatisfierProperty
    // 
    ::XMLSchema::string< ACE_TCHAR > const& SatisfierProperty::
    name () const
    {
      return *name_;
    }

    void SatisfierProperty::
    name (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *name_ = e;
    }

    // SatisfierProperty
    // 
    ::CIAO::Config_Handlers::SatisfierPropertyKind const& SatisfierProperty::
    kind () const
    {
      return *kind_;
    }

    void SatisfierProperty::
    kind (::CIAO::Config_Handlers::SatisfierPropertyKind const& e)
    {
      *kind_ = e;
    }

    // SatisfierProperty
    // 
    ::XMLSchema::boolean const& SatisfierProperty::
    dynamic () const
    {
      return *dynamic_;
    }

    void SatisfierProperty::
    dynamic (::XMLSchema::boolean const& e)
    {
      *dynamic_ = e;
    }

    // SatisfierProperty
    // 
    ::CIAO::Config_Handlers::Any const& SatisfierProperty::
    value () const
    {
      return *value_;
    }

    void SatisfierProperty::
    value (::CIAO::Config_Handlers::Any const& e)
    {
      *value_ = e;
    }


    // Resource
    // 

    Resource::
    Resource (::XMLSchema::string< ACE_TCHAR > const& name__)
    : 
    ::XSCRT::Type (), 
    name_ (new ::XMLSchema::string< ACE_TCHAR > (name__)),
    regulator__ ()
    {
      name_->container (this);
    }

    Resource::
    Resource (::CIAO::Config_Handlers::Resource const& s)
    :
    ::XSCRT::Type (),
    name_ (new ::XMLSchema::string< ACE_TCHAR > (*s.name_)),
    regulator__ ()
    {
      name_->container (this);
      {
        for (resourceType_const_iterator i (s.resourceType_.begin ());i != s.resourceType_.end ();++i) add_resourceType (*i);
      }

      {
        for (property_const_iterator i (s.property_.begin ());i != s.property_.end ();++i) add_property (*i);
      }
    }

    ::CIAO::Config_Handlers::Resource& Resource::
    operator= (::CIAO::Config_Handlers::Resource const& s)
    {
      name (s.name ());

      resourceType_.clear ();
      {
        for (resourceType_const_iterator i (s.resourceType_.begin ());i != s.resourceType_.end ();++i) add_resourceType (*i);
      }

      property_.clear ();
      {
        for (property_const_iterator i (s.property_.begin ());i != s.property_.end ();++i) add_property (*i);
      }

      return *this;
    }


    // Resource
    // 
    ::XMLSchema::string< ACE_TCHAR > const& Resource::
    name () const
    {
      return *name_;
    }

    void Resource::
    name (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *name_ = e;
    }

    // Resource
    // 
    Resource::resourceType_iterator Resource::
    begin_resourceType ()
    {
      return resourceType_.begin ();
    }

    Resource::resourceType_iterator Resource::
    end_resourceType ()
    {
      return resourceType_.end ();
    }

    Resource::resourceType_const_iterator Resource::
    begin_resourceType () const
    {
      return resourceType_.begin ();
    }

    Resource::resourceType_const_iterator Resource::
    end_resourceType () const
    {
      return resourceType_.end ();
    }

    void Resource::
    add_resourceType (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      resourceType_.push_back (e);
    }

    size_t Resource::
    count_resourceType(void) const
    {
      return resourceType_.size ();
    }

    // Resource
    // 
    Resource::property_iterator Resource::
    begin_property ()
    {
      return property_.begin ();
    }

    Resource::property_iterator Resource::
    end_property ()
    {
      return property_.end ();
    }

    Resource::property_const_iterator Resource::
    begin_property () const
    {
      return property_.begin ();
    }

    Resource::property_const_iterator Resource::
    end_property () const
    {
      return property_.end ();
    }

    void Resource::
    add_property (::CIAO::Config_Handlers::SatisfierProperty const& e)
    {
      property_.push_back (e);
    }

    size_t Resource::
    count_property(void) const
    {
      return property_.size ();
    }


    // Requirement
    // 

    Requirement::
    Requirement (::XMLSchema::string< ACE_TCHAR > const& resourceType__,
                 ::XMLSchema::string< ACE_TCHAR > const& name__)
    : 
    ::XSCRT::Type (), 
    resourceType_ (new ::XMLSchema::string< ACE_TCHAR > (resourceType__)),
    name_ (new ::XMLSchema::string< ACE_TCHAR > (name__)),
    regulator__ ()
    {
      resourceType_->container (this);
      name_->container (this);
    }

    Requirement::
    Requirement (::CIAO::Config_Handlers::Requirement const& s)
    :
    ::XSCRT::Type (),
    resourceType_ (new ::XMLSchema::string< ACE_TCHAR > (*s.resourceType_)),
    name_ (new ::XMLSchema::string< ACE_TCHAR > (*s.name_)),
    regulator__ ()
    {
      resourceType_->container (this);
      name_->container (this);
      {
        for (property_const_iterator i (s.property_.begin ());i != s.property_.end ();++i) add_property (*i);
      }
    }

    ::CIAO::Config_Handlers::Requirement& Requirement::
    operator= (::CIAO::Config_Handlers::Requirement const& s)
    {
      resourceType (s.resourceType ());

      name (s.name ());

      property_.clear ();
      {
        for (property_const_iterator i (s.property_.begin ());i != s.property_.end ();++i) add_property (*i);
      }

      return *this;
    }


    // Requirement
    // 
    ::XMLSchema::string< ACE_TCHAR > const& Requirement::
    resourceType () const
    {
      return *resourceType_;
    }

    void Requirement::
    resourceType (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *resourceType_ = e;
    }

    // Requirement
    // 
    ::XMLSchema::string< ACE_TCHAR > const& Requirement::
    name () const
    {
      return *name_;
    }

    void Requirement::
    name (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *name_ = e;
    }

    // Requirement
    // 
    Requirement::property_iterator Requirement::
    begin_property ()
    {
      return property_.begin ();
    }

    Requirement::property_iterator Requirement::
    end_property ()
    {
      return property_.end ();
    }

    Requirement::property_const_iterator Requirement::
    begin_property () const
    {
      return property_.begin ();
    }

    Requirement::property_const_iterator Requirement::
    end_property () const
    {
      return property_.end ();
    }

    void Requirement::
    add_property (::CIAO::Config_Handlers::Property const& e)
    {
      property_.push_back (e);
    }

    size_t Requirement::
    count_property(void) const
    {
      return property_.size ();
    }


    // ResourceDeploymentDescription
    // 

    ResourceDeploymentDescription::
    ResourceDeploymentDescription (::XMLSchema::string< ACE_TCHAR > const& requirementName__,
                                   ::XMLSchema::string< ACE_TCHAR > const& resourceName__)
    : 
    ::XSCRT::Type (), 
    requirementName_ (new ::XMLSchema::string< ACE_TCHAR > (requirementName__)),
    resourceName_ (new ::XMLSchema::string< ACE_TCHAR > (resourceName__)),
    regulator__ ()
    {
      requirementName_->container (this);
      resourceName_->container (this);
    }

    ResourceDeploymentDescription::
    ResourceDeploymentDescription (::CIAO::Config_Handlers::ResourceDeploymentDescription const& s)
    :
    ::XSCRT::Type (),
    requirementName_ (new ::XMLSchema::string< ACE_TCHAR > (*s.requirementName_)),
    resourceName_ (new ::XMLSchema::string< ACE_TCHAR > (*s.resourceName_)),
    regulator__ ()
    {
      requirementName_->container (this);
      resourceName_->container (this);
      {
        for (property_const_iterator i (s.property_.begin ());i != s.property_.end ();++i) add_property (*i);
      }
    }

    ::CIAO::Config_Handlers::ResourceDeploymentDescription& ResourceDeploymentDescription::
    operator= (::CIAO::Config_Handlers::ResourceDeploymentDescription const& s)
    {
      requirementName (s.requirementName ());

      resourceName (s.resourceName ());

      property_.clear ();
      {
        for (property_const_iterator i (s.property_.begin ());i != s.property_.end ();++i) add_property (*i);
      }

      return *this;
    }


    // ResourceDeploymentDescription
    // 
    ::XMLSchema::string< ACE_TCHAR > const& ResourceDeploymentDescription::
    requirementName () const
    {
      return *requirementName_;
    }

    void ResourceDeploymentDescription::
    requirementName (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *requirementName_ = e;
    }

    // ResourceDeploymentDescription
    // 
    ::XMLSchema::string< ACE_TCHAR > const& ResourceDeploymentDescription::
    resourceName () const
    {
      return *resourceName_;
    }

    void ResourceDeploymentDescription::
    resourceName (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *resourceName_ = e;
    }

    // ResourceDeploymentDescription
    // 
    ResourceDeploymentDescription::property_iterator ResourceDeploymentDescription::
    begin_property ()
    {
      return property_.begin ();
    }

    ResourceDeploymentDescription::property_iterator ResourceDeploymentDescription::
    end_property ()
    {
      return property_.end ();
    }

    ResourceDeploymentDescription::property_const_iterator ResourceDeploymentDescription::
    begin_property () const
    {
      return property_.begin ();
    }

    ResourceDeploymentDescription::property_const_iterator ResourceDeploymentDescription::
    end_property () const
    {
      return property_.end ();
    }

    void ResourceDeploymentDescription::
    add_property (::CIAO::Config_Handlers::Property const& e)
    {
      property_.push_back (e);
    }

    size_t ResourceDeploymentDescription::
    count_property(void) const
    {
      return property_.size ();
    }


    // ArtifactDeploymentDescription
    // 

    ArtifactDeploymentDescription::
    ArtifactDeploymentDescription (::XMLSchema::string< ACE_TCHAR > const& name__,
                                   ::XMLSchema::string< ACE_TCHAR > const& node__)
    : 
    ::XSCRT::Type (), 
    name_ (new ::XMLSchema::string< ACE_TCHAR > (name__)),
    node_ (new ::XMLSchema::string< ACE_TCHAR > (node__)),
    regulator__ ()
    {
      name_->container (this);
      node_->container (this);
    }

    ArtifactDeploymentDescription::
    ArtifactDeploymentDescription (::CIAO::Config_Handlers::ArtifactDeploymentDescription const& s)
    :
    ::XSCRT::Type (),
    name_ (new ::XMLSchema::string< ACE_TCHAR > (*s.name_)),
    node_ (new ::XMLSchema::string< ACE_TCHAR > (*s.node_)),
    id_ (s.id_.get () ? new ::XMLSchema::ID< ACE_TCHAR > (*s.id_) : 0),
    regulator__ ()
    {
      name_->container (this);
      {
        for (source_const_iterator i (s.source_.begin ());i != s.source_.end ();++i) add_source (*i);
      }

      node_->container (this);
      {
        for (location_const_iterator i (s.location_.begin ());i != s.location_.end ();++i) add_location (*i);
      }

      {
        for (execParameter_const_iterator i (s.execParameter_.begin ());i != s.execParameter_.end ();++i) add_execParameter (*i);
      }

      {
        for (deployRequirement_const_iterator i (s.deployRequirement_.begin ());i != s.deployRequirement_.end ();++i) add_deployRequirement (*i);
      }

      {
        for (deployedResource_const_iterator i (s.deployedResource_.begin ());i != s.deployedResource_.end ();++i) add_deployedResource (*i);
      }

      if (id_.get ()) id_->container (this);
    }

    ::CIAO::Config_Handlers::ArtifactDeploymentDescription& ArtifactDeploymentDescription::
    operator= (::CIAO::Config_Handlers::ArtifactDeploymentDescription const& s)
    {
      name (s.name ());

      source_.clear ();
      {
        for (source_const_iterator i (s.source_.begin ());i != s.source_.end ();++i) add_source (*i);
      }

      node (s.node ());

      location_.clear ();
      {
        for (location_const_iterator i (s.location_.begin ());i != s.location_.end ();++i) add_location (*i);
      }

      execParameter_.clear ();
      {
        for (execParameter_const_iterator i (s.execParameter_.begin ());i != s.execParameter_.end ();++i) add_execParameter (*i);
      }

      deployRequirement_.clear ();
      {
        for (deployRequirement_const_iterator i (s.deployRequirement_.begin ());i != s.deployRequirement_.end ();++i) add_deployRequirement (*i);
      }

      deployedResource_.clear ();
      {
        for (deployedResource_const_iterator i (s.deployedResource_.begin ());i != s.deployedResource_.end ();++i) add_deployedResource (*i);
      }

      if (s.id_.get ()) id (*(s.id_));
      else id_ = ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > (0);

      return *this;
    }


    // ArtifactDeploymentDescription
    // 
    ::XMLSchema::string< ACE_TCHAR > const& ArtifactDeploymentDescription::
    name () const
    {
      return *name_;
    }

    void ArtifactDeploymentDescription::
    name (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *name_ = e;
    }

    // ArtifactDeploymentDescription
    // 
    ArtifactDeploymentDescription::source_iterator ArtifactDeploymentDescription::
    begin_source ()
    {
      return source_.begin ();
    }

    ArtifactDeploymentDescription::source_iterator ArtifactDeploymentDescription::
    end_source ()
    {
      return source_.end ();
    }

    ArtifactDeploymentDescription::source_const_iterator ArtifactDeploymentDescription::
    begin_source () const
    {
      return source_.begin ();
    }

    ArtifactDeploymentDescription::source_const_iterator ArtifactDeploymentDescription::
    end_source () const
    {
      return source_.end ();
    }

    void ArtifactDeploymentDescription::
    add_source (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      source_.push_back (e);
    }

    size_t ArtifactDeploymentDescription::
    count_source(void) const
    {
      return source_.size ();
    }

    // ArtifactDeploymentDescription
    // 
    ::XMLSchema::string< ACE_TCHAR > const& ArtifactDeploymentDescription::
    node () const
    {
      return *node_;
    }

    void ArtifactDeploymentDescription::
    node (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *node_ = e;
    }

    // ArtifactDeploymentDescription
    // 
    ArtifactDeploymentDescription::location_iterator ArtifactDeploymentDescription::
    begin_location ()
    {
      return location_.begin ();
    }

    ArtifactDeploymentDescription::location_iterator ArtifactDeploymentDescription::
    end_location ()
    {
      return location_.end ();
    }

    ArtifactDeploymentDescription::location_const_iterator ArtifactDeploymentDescription::
    begin_location () const
    {
      return location_.begin ();
    }

    ArtifactDeploymentDescription::location_const_iterator ArtifactDeploymentDescription::
    end_location () const
    {
      return location_.end ();
    }

    void ArtifactDeploymentDescription::
    add_location (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      location_.push_back (e);
    }

    size_t ArtifactDeploymentDescription::
    count_location(void) const
    {
      return location_.size ();
    }

    // ArtifactDeploymentDescription
    // 
    ArtifactDeploymentDescription::execParameter_iterator ArtifactDeploymentDescription::
    begin_execParameter ()
    {
      return execParameter_.begin ();
    }

    ArtifactDeploymentDescription::execParameter_iterator ArtifactDeploymentDescription::
    end_execParameter ()
    {
      return execParameter_.end ();
    }

    ArtifactDeploymentDescription::execParameter_const_iterator ArtifactDeploymentDescription::
    begin_execParameter () const
    {
      return execParameter_.begin ();
    }

    ArtifactDeploymentDescription::execParameter_const_iterator ArtifactDeploymentDescription::
    end_execParameter () const
    {
      return execParameter_.end ();
    }

    void ArtifactDeploymentDescription::
    add_execParameter (::CIAO::Config_Handlers::Property const& e)
    {
      execParameter_.push_back (e);
    }

    size_t ArtifactDeploymentDescription::
    count_execParameter(void) const
    {
      return execParameter_.size ();
    }

    // ArtifactDeploymentDescription
    // 
    ArtifactDeploymentDescription::deployRequirement_iterator ArtifactDeploymentDescription::
    begin_deployRequirement ()
    {
      return deployRequirement_.begin ();
    }

    ArtifactDeploymentDescription::deployRequirement_iterator ArtifactDeploymentDescription::
    end_deployRequirement ()
    {
      return deployRequirement_.end ();
    }

    ArtifactDeploymentDescription::deployRequirement_const_iterator ArtifactDeploymentDescription::
    begin_deployRequirement () const
    {
      return deployRequirement_.begin ();
    }

    ArtifactDeploymentDescription::deployRequirement_const_iterator ArtifactDeploymentDescription::
    end_deployRequirement () const
    {
      return deployRequirement_.end ();
    }

    void ArtifactDeploymentDescription::
    add_deployRequirement (::CIAO::Config_Handlers::Requirement const& e)
    {
      deployRequirement_.push_back (e);
    }

    size_t ArtifactDeploymentDescription::
    count_deployRequirement(void) const
    {
      return deployRequirement_.size ();
    }

    // ArtifactDeploymentDescription
    // 
    ArtifactDeploymentDescription::deployedResource_iterator ArtifactDeploymentDescription::
    begin_deployedResource ()
    {
      return deployedResource_.begin ();
    }

    ArtifactDeploymentDescription::deployedResource_iterator ArtifactDeploymentDescription::
    end_deployedResource ()
    {
      return deployedResource_.end ();
    }

    ArtifactDeploymentDescription::deployedResource_const_iterator ArtifactDeploymentDescription::
    begin_deployedResource () const
    {
      return deployedResource_.begin ();
    }

    ArtifactDeploymentDescription::deployedResource_const_iterator ArtifactDeploymentDescription::
    end_deployedResource () const
    {
      return deployedResource_.end ();
    }

    void ArtifactDeploymentDescription::
    add_deployedResource (::CIAO::Config_Handlers::ResourceDeploymentDescription const& e)
    {
      deployedResource_.push_back (e);
    }

    size_t ArtifactDeploymentDescription::
    count_deployedResource(void) const
    {
      return deployedResource_.size ();
    }

    // ArtifactDeploymentDescription
    // 
    bool ArtifactDeploymentDescription::
    id_p () const
    {
      return id_.get () != 0;
    }

    ::XMLSchema::ID< ACE_TCHAR > const& ArtifactDeploymentDescription::
    id () const
    {
      return *id_;
    }

    ::XMLSchema::ID< ACE_TCHAR >& ArtifactDeploymentDescription::
    id ()
    {
      return *id_;
    }

    void ArtifactDeploymentDescription::
    id (::XMLSchema::ID< ACE_TCHAR > const& e)
    {
      if (id_.get ())
      {
        *id_ = e;
      }

      else
      {
        id_ = ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > (new ::XMLSchema::ID< ACE_TCHAR > (e));
        id_->container (this);
      }
    }


    // MonolithicDeploymentDescription
    // 

    MonolithicDeploymentDescription::
    MonolithicDeploymentDescription (::XMLSchema::string< ACE_TCHAR > const& name__)
    : 
    ::XSCRT::Type (), 
    name_ (new ::XMLSchema::string< ACE_TCHAR > (name__)),
    regulator__ ()
    {
      name_->container (this);
    }

    MonolithicDeploymentDescription::
    MonolithicDeploymentDescription (::CIAO::Config_Handlers::MonolithicDeploymentDescription const& s)
    :
    ::XSCRT::Type (),
    name_ (new ::XMLSchema::string< ACE_TCHAR > (*s.name_)),
    id_ (s.id_.get () ? new ::XMLSchema::ID< ACE_TCHAR > (*s.id_) : 0),
    regulator__ ()
    {
      name_->container (this);
      {
        for (source_const_iterator i (s.source_.begin ());i != s.source_.end ();++i) add_source (*i);
      }

      {
        for (artifact_const_iterator i (s.artifact_.begin ());i != s.artifact_.end ();++i) add_artifact (*i);
      }

      {
        for (execParameter_const_iterator i (s.execParameter_.begin ());i != s.execParameter_.end ();++i) add_execParameter (*i);
      }

      {
        for (deployRequirement_const_iterator i (s.deployRequirement_.begin ());i != s.deployRequirement_.end ();++i) add_deployRequirement (*i);
      }

      if (id_.get ()) id_->container (this);
    }

    ::CIAO::Config_Handlers::MonolithicDeploymentDescription& MonolithicDeploymentDescription::
    operator= (::CIAO::Config_Handlers::MonolithicDeploymentDescription const& s)
    {
      name (s.name ());

      source_.clear ();
      {
        for (source_const_iterator i (s.source_.begin ());i != s.source_.end ();++i) add_source (*i);
      }

      artifact_.clear ();
      {
        for (artifact_const_iterator i (s.artifact_.begin ());i != s.artifact_.end ();++i) add_artifact (*i);
      }

      execParameter_.clear ();
      {
        for (execParameter_const_iterator i (s.execParameter_.begin ());i != s.execParameter_.end ();++i) add_execParameter (*i);
      }

      deployRequirement_.clear ();
      {
        for (deployRequirement_const_iterator i (s.deployRequirement_.begin ());i != s.deployRequirement_.end ();++i) add_deployRequirement (*i);
      }

      if (s.id_.get ()) id (*(s.id_));
      else id_ = ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > (0);

      return *this;
    }


    // MonolithicDeploymentDescription
    // 
    ::XMLSchema::string< ACE_TCHAR > const& MonolithicDeploymentDescription::
    name () const
    {
      return *name_;
    }

    void MonolithicDeploymentDescription::
    name (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *name_ = e;
    }

    // MonolithicDeploymentDescription
    // 
    MonolithicDeploymentDescription::source_iterator MonolithicDeploymentDescription::
    begin_source ()
    {
      return source_.begin ();
    }

    MonolithicDeploymentDescription::source_iterator MonolithicDeploymentDescription::
    end_source ()
    {
      return source_.end ();
    }

    MonolithicDeploymentDescription::source_const_iterator MonolithicDeploymentDescription::
    begin_source () const
    {
      return source_.begin ();
    }

    MonolithicDeploymentDescription::source_const_iterator MonolithicDeploymentDescription::
    end_source () const
    {
      return source_.end ();
    }

    void MonolithicDeploymentDescription::
    add_source (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      source_.push_back (e);
    }

    size_t MonolithicDeploymentDescription::
    count_source(void) const
    {
      return source_.size ();
    }

    // MonolithicDeploymentDescription
    // 
    MonolithicDeploymentDescription::artifact_iterator MonolithicDeploymentDescription::
    begin_artifact ()
    {
      return artifact_.begin ();
    }

    MonolithicDeploymentDescription::artifact_iterator MonolithicDeploymentDescription::
    end_artifact ()
    {
      return artifact_.end ();
    }

    MonolithicDeploymentDescription::artifact_const_iterator MonolithicDeploymentDescription::
    begin_artifact () const
    {
      return artifact_.begin ();
    }

    MonolithicDeploymentDescription::artifact_const_iterator MonolithicDeploymentDescription::
    end_artifact () const
    {
      return artifact_.end ();
    }

    void MonolithicDeploymentDescription::
    add_artifact (::XMLSchema::IDREF< ACE_TCHAR > const& e)
    {
      artifact_.push_back (e);
    }

    size_t MonolithicDeploymentDescription::
    count_artifact(void) const
    {
      return artifact_.size ();
    }

    // MonolithicDeploymentDescription
    // 
    MonolithicDeploymentDescription::execParameter_iterator MonolithicDeploymentDescription::
    begin_execParameter ()
    {
      return execParameter_.begin ();
    }

    MonolithicDeploymentDescription::execParameter_iterator MonolithicDeploymentDescription::
    end_execParameter ()
    {
      return execParameter_.end ();
    }

    MonolithicDeploymentDescription::execParameter_const_iterator MonolithicDeploymentDescription::
    begin_execParameter () const
    {
      return execParameter_.begin ();
    }

    MonolithicDeploymentDescription::execParameter_const_iterator MonolithicDeploymentDescription::
    end_execParameter () const
    {
      return execParameter_.end ();
    }

    void MonolithicDeploymentDescription::
    add_execParameter (::CIAO::Config_Handlers::Property const& e)
    {
      execParameter_.push_back (e);
    }

    size_t MonolithicDeploymentDescription::
    count_execParameter(void) const
    {
      return execParameter_.size ();
    }

    // MonolithicDeploymentDescription
    // 
    MonolithicDeploymentDescription::deployRequirement_iterator MonolithicDeploymentDescription::
    begin_deployRequirement ()
    {
      return deployRequirement_.begin ();
    }

    MonolithicDeploymentDescription::deployRequirement_iterator MonolithicDeploymentDescription::
    end_deployRequirement ()
    {
      return deployRequirement_.end ();
    }

    MonolithicDeploymentDescription::deployRequirement_const_iterator MonolithicDeploymentDescription::
    begin_deployRequirement () const
    {
      return deployRequirement_.begin ();
    }

    MonolithicDeploymentDescription::deployRequirement_const_iterator MonolithicDeploymentDescription::
    end_deployRequirement () const
    {
      return deployRequirement_.end ();
    }

    void MonolithicDeploymentDescription::
    add_deployRequirement (::CIAO::Config_Handlers::Requirement const& e)
    {
      deployRequirement_.push_back (e);
    }

    size_t MonolithicDeploymentDescription::
    count_deployRequirement(void) const
    {
      return deployRequirement_.size ();
    }

    // MonolithicDeploymentDescription
    // 
    bool MonolithicDeploymentDescription::
    id_p () const
    {
      return id_.get () != 0;
    }

    ::XMLSchema::ID< ACE_TCHAR > const& MonolithicDeploymentDescription::
    id () const
    {
      return *id_;
    }

    ::XMLSchema::ID< ACE_TCHAR >& MonolithicDeploymentDescription::
    id ()
    {
      return *id_;
    }

    void MonolithicDeploymentDescription::
    id (::XMLSchema::ID< ACE_TCHAR > const& e)
    {
      if (id_.get ())
      {
        *id_ = e;
      }

      else
      {
        id_ = ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > (new ::XMLSchema::ID< ACE_TCHAR > (e));
        id_->container (this);
      }
    }


    // ResourceUsageKind
    // 

    ResourceUsageKind::Value ResourceUsageKind::
    integral () const
    {
      return v_;
    }

    bool
    operator== (::CIAO::Config_Handlers::ResourceUsageKind const& a, ::CIAO::Config_Handlers::ResourceUsageKind const& b)
    {
      return a.v_ == b.v_;
    }

    bool
    operator!= (::CIAO::Config_Handlers::ResourceUsageKind const& a, ::CIAO::Config_Handlers::ResourceUsageKind const& b)
    {
      return a.v_ != b.v_;
    }

    ResourceUsageKind::
    ResourceUsageKind (ResourceUsageKind::Value v)
    : v_ (v)
    {
    }

    // InstanceResourceDeploymentDescription
    // 

    InstanceResourceDeploymentDescription::
    InstanceResourceDeploymentDescription (::CIAO::Config_Handlers::ResourceUsageKind const& resourceUsage__,
                                           ::XMLSchema::string< ACE_TCHAR > const& requirementName__,
                                           ::XMLSchema::string< ACE_TCHAR > const& resourceName__)
    : 
    ::XSCRT::Type (), 
    resourceUsage_ (new ::CIAO::Config_Handlers::ResourceUsageKind (resourceUsage__)),
    requirementName_ (new ::XMLSchema::string< ACE_TCHAR > (requirementName__)),
    resourceName_ (new ::XMLSchema::string< ACE_TCHAR > (resourceName__)),
    regulator__ ()
    {
      resourceUsage_->container (this);
      requirementName_->container (this);
      resourceName_->container (this);
    }

    InstanceResourceDeploymentDescription::
    InstanceResourceDeploymentDescription (::CIAO::Config_Handlers::InstanceResourceDeploymentDescription const& s)
    :
    ::XSCRT::Type (),
    resourceUsage_ (new ::CIAO::Config_Handlers::ResourceUsageKind (*s.resourceUsage_)),
    requirementName_ (new ::XMLSchema::string< ACE_TCHAR > (*s.requirementName_)),
    resourceName_ (new ::XMLSchema::string< ACE_TCHAR > (*s.resourceName_)),
    regulator__ ()
    {
      resourceUsage_->container (this);
      requirementName_->container (this);
      resourceName_->container (this);
      {
        for (property_const_iterator i (s.property_.begin ());i != s.property_.end ();++i) add_property (*i);
      }
    }

    ::CIAO::Config_Handlers::InstanceResourceDeploymentDescription& InstanceResourceDeploymentDescription::
    operator= (::CIAO::Config_Handlers::InstanceResourceDeploymentDescription const& s)
    {
      resourceUsage (s.resourceUsage ());

      requirementName (s.requirementName ());

      resourceName (s.resourceName ());

      property_.clear ();
      {
        for (property_const_iterator i (s.property_.begin ());i != s.property_.end ();++i) add_property (*i);
      }

      return *this;
    }


    // InstanceResourceDeploymentDescription
    // 
    ::CIAO::Config_Handlers::ResourceUsageKind const& InstanceResourceDeploymentDescription::
    resourceUsage () const
    {
      return *resourceUsage_;
    }

    void InstanceResourceDeploymentDescription::
    resourceUsage (::CIAO::Config_Handlers::ResourceUsageKind const& e)
    {
      *resourceUsage_ = e;
    }

    // InstanceResourceDeploymentDescription
    // 
    ::XMLSchema::string< ACE_TCHAR > const& InstanceResourceDeploymentDescription::
    requirementName () const
    {
      return *requirementName_;
    }

    void InstanceResourceDeploymentDescription::
    requirementName (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *requirementName_ = e;
    }

    // InstanceResourceDeploymentDescription
    // 
    ::XMLSchema::string< ACE_TCHAR > const& InstanceResourceDeploymentDescription::
    resourceName () const
    {
      return *resourceName_;
    }

    void InstanceResourceDeploymentDescription::
    resourceName (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *resourceName_ = e;
    }

    // InstanceResourceDeploymentDescription
    // 
    InstanceResourceDeploymentDescription::property_iterator InstanceResourceDeploymentDescription::
    begin_property ()
    {
      return property_.begin ();
    }

    InstanceResourceDeploymentDescription::property_iterator InstanceResourceDeploymentDescription::
    end_property ()
    {
      return property_.end ();
    }

    InstanceResourceDeploymentDescription::property_const_iterator InstanceResourceDeploymentDescription::
    begin_property () const
    {
      return property_.begin ();
    }

    InstanceResourceDeploymentDescription::property_const_iterator InstanceResourceDeploymentDescription::
    end_property () const
    {
      return property_.end ();
    }

    void InstanceResourceDeploymentDescription::
    add_property (::CIAO::Config_Handlers::Property const& e)
    {
      property_.push_back (e);
    }

    size_t InstanceResourceDeploymentDescription::
    count_property(void) const
    {
      return property_.size ();
    }


    // InstanceDeploymentDescription
    // 

    InstanceDeploymentDescription::
    InstanceDeploymentDescription (::XMLSchema::string< ACE_TCHAR > const& name__,
                                   ::XMLSchema::string< ACE_TCHAR > const& node__,
                                   ::XMLSchema::string< ACE_TCHAR > const& source__,
                                   ::XMLSchema::IDREF< ACE_TCHAR > const& implementation__)
    : 
    ::XSCRT::Type (), 
    name_ (new ::XMLSchema::string< ACE_TCHAR > (name__)),
    node_ (new ::XMLSchema::string< ACE_TCHAR > (node__)),
    source_ (new ::XMLSchema::string< ACE_TCHAR > (source__)),
    implementation_ (new ::XMLSchema::IDREF< ACE_TCHAR > (implementation__)),
    regulator__ ()
    {
      name_->container (this);
      node_->container (this);
      source_->container (this);
      implementation_->container (this);
    }

    InstanceDeploymentDescription::
    InstanceDeploymentDescription (::CIAO::Config_Handlers::InstanceDeploymentDescription const& s)
    :
    ::XSCRT::Type (),
    name_ (new ::XMLSchema::string< ACE_TCHAR > (*s.name_)),
    node_ (new ::XMLSchema::string< ACE_TCHAR > (*s.node_)),
    source_ (new ::XMLSchema::string< ACE_TCHAR > (*s.source_)),
    implementation_ (new ::XMLSchema::IDREF< ACE_TCHAR > (*s.implementation_)),
    deployedSharedResource_ (s.deployedSharedResource_.get () ? new ::CIAO::Config_Handlers::InstanceResourceDeploymentDescription (*s.deployedSharedResource_) : 0),
    id_ (s.id_.get () ? new ::XMLSchema::ID< ACE_TCHAR > (*s.id_) : 0),
    regulator__ ()
    {
      name_->container (this);
      node_->container (this);
      source_->container (this);
      implementation_->container (this);
      {
        for (configProperty_const_iterator i (s.configProperty_.begin ());i != s.configProperty_.end ();++i) add_configProperty (*i);
      }

      {
        for (deployedResource_const_iterator i (s.deployedResource_.begin ());i != s.deployedResource_.end ();++i) add_deployedResource (*i);
      }

      if (deployedSharedResource_.get ()) deployedSharedResource_->container (this);
      if (id_.get ()) id_->container (this);
    }

    ::CIAO::Config_Handlers::InstanceDeploymentDescription& InstanceDeploymentDescription::
    operator= (::CIAO::Config_Handlers::InstanceDeploymentDescription const& s)
    {
      name (s.name ());

      node (s.node ());

      source (s.source ());

      implementation (s.implementation ());

      configProperty_.clear ();
      {
        for (configProperty_const_iterator i (s.configProperty_.begin ());i != s.configProperty_.end ();++i) add_configProperty (*i);
      }

      deployedResource_.clear ();
      {
        for (deployedResource_const_iterator i (s.deployedResource_.begin ());i != s.deployedResource_.end ();++i) add_deployedResource (*i);
      }

      if (s.deployedSharedResource_.get ()) deployedSharedResource (*(s.deployedSharedResource_));
      else deployedSharedResource_ = ::std::auto_ptr< ::CIAO::Config_Handlers::InstanceResourceDeploymentDescription > (0);

      if (s.id_.get ()) id (*(s.id_));
      else id_ = ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > (0);

      return *this;
    }


    // InstanceDeploymentDescription
    // 
    ::XMLSchema::string< ACE_TCHAR > const& InstanceDeploymentDescription::
    name () const
    {
      return *name_;
    }

    void InstanceDeploymentDescription::
    name (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *name_ = e;
    }

    // InstanceDeploymentDescription
    // 
    ::XMLSchema::string< ACE_TCHAR > const& InstanceDeploymentDescription::
    node () const
    {
      return *node_;
    }

    void InstanceDeploymentDescription::
    node (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *node_ = e;
    }

    // InstanceDeploymentDescription
    // 
    ::XMLSchema::string< ACE_TCHAR > const& InstanceDeploymentDescription::
    source () const
    {
      return *source_;
    }

    void InstanceDeploymentDescription::
    source (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *source_ = e;
    }

    // InstanceDeploymentDescription
    // 
    ::XMLSchema::IDREF< ACE_TCHAR > const& InstanceDeploymentDescription::
    implementation () const
    {
      return *implementation_;
    }

    void InstanceDeploymentDescription::
    implementation (::XMLSchema::IDREF< ACE_TCHAR > const& e)
    {
      *implementation_ = e;
    }

    // InstanceDeploymentDescription
    // 
    InstanceDeploymentDescription::configProperty_iterator InstanceDeploymentDescription::
    begin_configProperty ()
    {
      return configProperty_.begin ();
    }

    InstanceDeploymentDescription::configProperty_iterator InstanceDeploymentDescription::
    end_configProperty ()
    {
      return configProperty_.end ();
    }

    InstanceDeploymentDescription::configProperty_const_iterator InstanceDeploymentDescription::
    begin_configProperty () const
    {
      return configProperty_.begin ();
    }

    InstanceDeploymentDescription::configProperty_const_iterator InstanceDeploymentDescription::
    end_configProperty () const
    {
      return configProperty_.end ();
    }

    void InstanceDeploymentDescription::
    add_configProperty (::CIAO::Config_Handlers::Property const& e)
    {
      configProperty_.push_back (e);
    }

    size_t InstanceDeploymentDescription::
    count_configProperty(void) const
    {
      return configProperty_.size ();
    }

    // InstanceDeploymentDescription
    // 
    InstanceDeploymentDescription::deployedResource_iterator InstanceDeploymentDescription::
    begin_deployedResource ()
    {
      return deployedResource_.begin ();
    }

    InstanceDeploymentDescription::deployedResource_iterator InstanceDeploymentDescription::
    end_deployedResource ()
    {
      return deployedResource_.end ();
    }

    InstanceDeploymentDescription::deployedResource_const_iterator InstanceDeploymentDescription::
    begin_deployedResource () const
    {
      return deployedResource_.begin ();
    }

    InstanceDeploymentDescription::deployedResource_const_iterator InstanceDeploymentDescription::
    end_deployedResource () const
    {
      return deployedResource_.end ();
    }

    void InstanceDeploymentDescription::
    add_deployedResource (::CIAO::Config_Handlers::InstanceResourceDeploymentDescription const& e)
    {
      deployedResource_.push_back (e);
    }

    size_t InstanceDeploymentDescription::
    count_deployedResource(void) const
    {
      return deployedResource_.size ();
    }

    // InstanceDeploymentDescription
    // 
    bool InstanceDeploymentDescription::
    deployedSharedResource_p () const
    {
      return deployedSharedResource_.get () != 0;
    }

    ::CIAO::Config_Handlers::InstanceResourceDeploymentDescription const& InstanceDeploymentDescription::
    deployedSharedResource () const
    {
      return *deployedSharedResource_;
    }

    void InstanceDeploymentDescription::
    deployedSharedResource (::CIAO::Config_Handlers::InstanceResourceDeploymentDescription const& e)
    {
      if (deployedSharedResource_.get ())
      {
        *deployedSharedResource_ = e;
      }

      else
      {
        deployedSharedResource_ = ::std::auto_ptr< ::CIAO::Config_Handlers::InstanceResourceDeploymentDescription > (new ::CIAO::Config_Handlers::InstanceResourceDeploymentDescription (e));
        deployedSharedResource_->container (this);
      }
    }

    // InstanceDeploymentDescription
    // 
    bool InstanceDeploymentDescription::
    id_p () const
    {
      return id_.get () != 0;
    }

    ::XMLSchema::ID< ACE_TCHAR > const& InstanceDeploymentDescription::
    id () const
    {
      return *id_;
    }

    ::XMLSchema::ID< ACE_TCHAR >& InstanceDeploymentDescription::
    id ()
    {
      return *id_;
    }

    void InstanceDeploymentDescription::
    id (::XMLSchema::ID< ACE_TCHAR > const& e)
    {
      if (id_.get ())
      {
        *id_ = e;
      }

      else
      {
        id_ = ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > (new ::XMLSchema::ID< ACE_TCHAR > (e));
        id_->container (this);
      }
    }


    // CCMComponentPortKind
    // 

    CCMComponentPortKind::Value CCMComponentPortKind::
    integral () const
    {
      return v_;
    }

    bool
    operator== (::CIAO::Config_Handlers::CCMComponentPortKind const& a, ::CIAO::Config_Handlers::CCMComponentPortKind const& b)
    {
      return a.v_ == b.v_;
    }

    bool
    operator!= (::CIAO::Config_Handlers::CCMComponentPortKind const& a, ::CIAO::Config_Handlers::CCMComponentPortKind const& b)
    {
      return a.v_ != b.v_;
    }

    CCMComponentPortKind::
    CCMComponentPortKind (CCMComponentPortKind::Value v)
    : v_ (v)
    {
    }

    // ComponentPortDescription
    // 

    ComponentPortDescription::
    ComponentPortDescription (::XMLSchema::string< ACE_TCHAR > const& name__,
                              ::XMLSchema::boolean const& provider__,
                              ::XMLSchema::boolean const& exclusiveProvider__,
                              ::XMLSchema::boolean const& exclusiveUser__,
                              ::XMLSchema::boolean const& optional__,
                              ::CIAO::Config_Handlers::CCMComponentPortKind const& kind__)
    : 
    ::XSCRT::Type (), 
    name_ (new ::XMLSchema::string< ACE_TCHAR > (name__)),
    provider_ (new ::XMLSchema::boolean (provider__)),
    exclusiveProvider_ (new ::XMLSchema::boolean (exclusiveProvider__)),
    exclusiveUser_ (new ::XMLSchema::boolean (exclusiveUser__)),
    optional_ (new ::XMLSchema::boolean (optional__)),
    kind_ (new ::CIAO::Config_Handlers::CCMComponentPortKind (kind__)),
    regulator__ ()
    {
      name_->container (this);
      provider_->container (this);
      exclusiveProvider_->container (this);
      exclusiveUser_->container (this);
      optional_->container (this);
      kind_->container (this);
    }

    ComponentPortDescription::
    ComponentPortDescription (::CIAO::Config_Handlers::ComponentPortDescription const& s)
    :
    ::XSCRT::Type (),
    name_ (new ::XMLSchema::string< ACE_TCHAR > (*s.name_)),
    specificType_ (s.specificType_.get () ? new ::XMLSchema::string< ACE_TCHAR > (*s.specificType_) : 0),
    provider_ (new ::XMLSchema::boolean (*s.provider_)),
    exclusiveProvider_ (new ::XMLSchema::boolean (*s.exclusiveProvider_)),
    exclusiveUser_ (new ::XMLSchema::boolean (*s.exclusiveUser_)),
    optional_ (new ::XMLSchema::boolean (*s.optional_)),
    kind_ (new ::CIAO::Config_Handlers::CCMComponentPortKind (*s.kind_)),
    regulator__ ()
    {
      name_->container (this);
      if (specificType_.get ()) specificType_->container (this);
      {
        for (supportedType_const_iterator i (s.supportedType_.begin ());i != s.supportedType_.end ();++i) add_supportedType (*i);
      }

      provider_->container (this);
      exclusiveProvider_->container (this);
      exclusiveUser_->container (this);
      optional_->container (this);
      kind_->container (this);
    }

    ::CIAO::Config_Handlers::ComponentPortDescription& ComponentPortDescription::
    operator= (::CIAO::Config_Handlers::ComponentPortDescription const& s)
    {
      name (s.name ());

      if (s.specificType_.get ()) specificType (*(s.specificType_));
      else specificType_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (0);

      supportedType_.clear ();
      {
        for (supportedType_const_iterator i (s.supportedType_.begin ());i != s.supportedType_.end ();++i) add_supportedType (*i);
      }

      provider (s.provider ());

      exclusiveProvider (s.exclusiveProvider ());

      exclusiveUser (s.exclusiveUser ());

      optional (s.optional ());

      kind (s.kind ());

      return *this;
    }


    // ComponentPortDescription
    // 
    ::XMLSchema::string< ACE_TCHAR > const& ComponentPortDescription::
    name () const
    {
      return *name_;
    }

    void ComponentPortDescription::
    name (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *name_ = e;
    }

    // ComponentPortDescription
    // 
    bool ComponentPortDescription::
    specificType_p () const
    {
      return specificType_.get () != 0;
    }

    ::XMLSchema::string< ACE_TCHAR > const& ComponentPortDescription::
    specificType () const
    {
      return *specificType_;
    }

    void ComponentPortDescription::
    specificType (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      if (specificType_.get ())
      {
        *specificType_ = e;
      }

      else
      {
        specificType_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
        specificType_->container (this);
      }
    }

    // ComponentPortDescription
    // 
    ComponentPortDescription::supportedType_iterator ComponentPortDescription::
    begin_supportedType ()
    {
      return supportedType_.begin ();
    }

    ComponentPortDescription::supportedType_iterator ComponentPortDescription::
    end_supportedType ()
    {
      return supportedType_.end ();
    }

    ComponentPortDescription::supportedType_const_iterator ComponentPortDescription::
    begin_supportedType () const
    {
      return supportedType_.begin ();
    }

    ComponentPortDescription::supportedType_const_iterator ComponentPortDescription::
    end_supportedType () const
    {
      return supportedType_.end ();
    }

    void ComponentPortDescription::
    add_supportedType (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      supportedType_.push_back (e);
    }

    size_t ComponentPortDescription::
    count_supportedType(void) const
    {
      return supportedType_.size ();
    }

    // ComponentPortDescription
    // 
    ::XMLSchema::boolean const& ComponentPortDescription::
    provider () const
    {
      return *provider_;
    }

    void ComponentPortDescription::
    provider (::XMLSchema::boolean const& e)
    {
      *provider_ = e;
    }

    // ComponentPortDescription
    // 
    ::XMLSchema::boolean const& ComponentPortDescription::
    exclusiveProvider () const
    {
      return *exclusiveProvider_;
    }

    void ComponentPortDescription::
    exclusiveProvider (::XMLSchema::boolean const& e)
    {
      *exclusiveProvider_ = e;
    }

    // ComponentPortDescription
    // 
    ::XMLSchema::boolean const& ComponentPortDescription::
    exclusiveUser () const
    {
      return *exclusiveUser_;
    }

    void ComponentPortDescription::
    exclusiveUser (::XMLSchema::boolean const& e)
    {
      *exclusiveUser_ = e;
    }

    // ComponentPortDescription
    // 
    ::XMLSchema::boolean const& ComponentPortDescription::
    optional () const
    {
      return *optional_;
    }

    void ComponentPortDescription::
    optional (::XMLSchema::boolean const& e)
    {
      *optional_ = e;
    }

    // ComponentPortDescription
    // 
    ::CIAO::Config_Handlers::CCMComponentPortKind const& ComponentPortDescription::
    kind () const
    {
      return *kind_;
    }

    void ComponentPortDescription::
    kind (::CIAO::Config_Handlers::CCMComponentPortKind const& e)
    {
      *kind_ = e;
    }


    // ComponentPropertyDescription
    // 

    ComponentPropertyDescription::
    ComponentPropertyDescription (::XMLSchema::string< ACE_TCHAR > const& name__,
                                  ::CIAO::Config_Handlers::DataType const& type__)
    : 
    ::XSCRT::Type (), 
    name_ (new ::XMLSchema::string< ACE_TCHAR > (name__)),
    type_ (new ::CIAO::Config_Handlers::DataType (type__)),
    regulator__ ()
    {
      name_->container (this);
      type_->container (this);
    }

    ComponentPropertyDescription::
    ComponentPropertyDescription (::CIAO::Config_Handlers::ComponentPropertyDescription const& s)
    :
    ::XSCRT::Type (),
    name_ (new ::XMLSchema::string< ACE_TCHAR > (*s.name_)),
    type_ (new ::CIAO::Config_Handlers::DataType (*s.type_)),
    regulator__ ()
    {
      name_->container (this);
      type_->container (this);
    }

    ::CIAO::Config_Handlers::ComponentPropertyDescription& ComponentPropertyDescription::
    operator= (::CIAO::Config_Handlers::ComponentPropertyDescription const& s)
    {
      name (s.name ());

      type (s.type ());

      return *this;
    }


    // ComponentPropertyDescription
    // 
    ::XMLSchema::string< ACE_TCHAR > const& ComponentPropertyDescription::
    name () const
    {
      return *name_;
    }

    void ComponentPropertyDescription::
    name (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *name_ = e;
    }

    // ComponentPropertyDescription
    // 
    ::CIAO::Config_Handlers::DataType const& ComponentPropertyDescription::
    type () const
    {
      return *type_;
    }

    void ComponentPropertyDescription::
    type (::CIAO::Config_Handlers::DataType const& e)
    {
      *type_ = e;
    }


    // ComponentExternalPortEndpoint
    // 

    ComponentExternalPortEndpoint::
    ComponentExternalPortEndpoint (::XMLSchema::string< ACE_TCHAR > const& portName__)
    : 
    ::XSCRT::Type (), 
    portName_ (new ::XMLSchema::string< ACE_TCHAR > (portName__)),
    regulator__ ()
    {
      portName_->container (this);
    }

    ComponentExternalPortEndpoint::
    ComponentExternalPortEndpoint (::CIAO::Config_Handlers::ComponentExternalPortEndpoint const& s)
    :
    ::XSCRT::Type (),
    portName_ (new ::XMLSchema::string< ACE_TCHAR > (*s.portName_)),
    regulator__ ()
    {
      portName_->container (this);
    }

    ::CIAO::Config_Handlers::ComponentExternalPortEndpoint& ComponentExternalPortEndpoint::
    operator= (::CIAO::Config_Handlers::ComponentExternalPortEndpoint const& s)
    {
      portName (s.portName ());

      return *this;
    }


    // ComponentExternalPortEndpoint
    // 
    ::XMLSchema::string< ACE_TCHAR > const& ComponentExternalPortEndpoint::
    portName () const
    {
      return *portName_;
    }

    void ComponentExternalPortEndpoint::
    portName (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *portName_ = e;
    }


    // PlanSubcomponentPortEndpoint
    // 

    PlanSubcomponentPortEndpoint::
    PlanSubcomponentPortEndpoint (::XMLSchema::string< ACE_TCHAR > const& portName__,
                                  ::CIAO::Config_Handlers::CCMComponentPortKind const& kind__,
                                  ::XMLSchema::IDREF< ACE_TCHAR > const& instance__)
    : 
    ::XSCRT::Type (), 
    portName_ (new ::XMLSchema::string< ACE_TCHAR > (portName__)),
    kind_ (new ::CIAO::Config_Handlers::CCMComponentPortKind (kind__)),
    instance_ (new ::XMLSchema::IDREF< ACE_TCHAR > (instance__)),
    regulator__ ()
    {
      portName_->container (this);
      kind_->container (this);
      instance_->container (this);
    }

    PlanSubcomponentPortEndpoint::
    PlanSubcomponentPortEndpoint (::CIAO::Config_Handlers::PlanSubcomponentPortEndpoint const& s)
    :
    ::XSCRT::Type (),
    portName_ (new ::XMLSchema::string< ACE_TCHAR > (*s.portName_)),
    provider_ (s.provider_.get () ? new ::XMLSchema::string< ACE_TCHAR > (*s.provider_) : 0),
    kind_ (new ::CIAO::Config_Handlers::CCMComponentPortKind (*s.kind_)),
    instance_ (new ::XMLSchema::IDREF< ACE_TCHAR > (*s.instance_)),
    regulator__ ()
    {
      portName_->container (this);
      if (provider_.get ()) provider_->container (this);
      kind_->container (this);
      instance_->container (this);
    }

    ::CIAO::Config_Handlers::PlanSubcomponentPortEndpoint& PlanSubcomponentPortEndpoint::
    operator= (::CIAO::Config_Handlers::PlanSubcomponentPortEndpoint const& s)
    {
      portName (s.portName ());

      if (s.provider_.get ()) provider (*(s.provider_));
      else provider_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (0);

      kind (s.kind ());

      instance (s.instance ());

      return *this;
    }


    // PlanSubcomponentPortEndpoint
    // 
    ::XMLSchema::string< ACE_TCHAR > const& PlanSubcomponentPortEndpoint::
    portName () const
    {
      return *portName_;
    }

    void PlanSubcomponentPortEndpoint::
    portName (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *portName_ = e;
    }

    // PlanSubcomponentPortEndpoint
    // 
    bool PlanSubcomponentPortEndpoint::
    provider_p () const
    {
      return provider_.get () != 0;
    }

    ::XMLSchema::string< ACE_TCHAR > const& PlanSubcomponentPortEndpoint::
    provider () const
    {
      return *provider_;
    }

    void PlanSubcomponentPortEndpoint::
    provider (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      if (provider_.get ())
      {
        *provider_ = e;
      }

      else
      {
        provider_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
        provider_->container (this);
      }
    }

    // PlanSubcomponentPortEndpoint
    // 
    ::CIAO::Config_Handlers::CCMComponentPortKind const& PlanSubcomponentPortEndpoint::
    kind () const
    {
      return *kind_;
    }

    void PlanSubcomponentPortEndpoint::
    kind (::CIAO::Config_Handlers::CCMComponentPortKind const& e)
    {
      *kind_ = e;
    }

    // PlanSubcomponentPortEndpoint
    // 
    ::XMLSchema::IDREF< ACE_TCHAR > const& PlanSubcomponentPortEndpoint::
    instance () const
    {
      return *instance_;
    }

    void PlanSubcomponentPortEndpoint::
    instance (::XMLSchema::IDREF< ACE_TCHAR > const& e)
    {
      *instance_ = e;
    }


    // ExternalReferenceEndpoint
    // 

    ExternalReferenceEndpoint::
    ExternalReferenceEndpoint (::XMLSchema::string< ACE_TCHAR > const& location__)
    : 
    ::XSCRT::Type (), 
    location_ (new ::XMLSchema::string< ACE_TCHAR > (location__)),
    regulator__ ()
    {
      location_->container (this);
    }

    ExternalReferenceEndpoint::
    ExternalReferenceEndpoint (::CIAO::Config_Handlers::ExternalReferenceEndpoint const& s)
    :
    ::XSCRT::Type (),
    location_ (new ::XMLSchema::string< ACE_TCHAR > (*s.location_)),
    regulator__ ()
    {
      location_->container (this);
    }

    ::CIAO::Config_Handlers::ExternalReferenceEndpoint& ExternalReferenceEndpoint::
    operator= (::CIAO::Config_Handlers::ExternalReferenceEndpoint const& s)
    {
      location (s.location ());

      return *this;
    }


    // ExternalReferenceEndpoint
    // 
    ::XMLSchema::string< ACE_TCHAR > const& ExternalReferenceEndpoint::
    location () const
    {
      return *location_;
    }

    void ExternalReferenceEndpoint::
    location (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *location_ = e;
    }


    // ConnectionResourceDeploymentDescription
    // 

    ConnectionResourceDeploymentDescription::
    ConnectionResourceDeploymentDescription (::XMLSchema::string< ACE_TCHAR > const& targetName__,
                                             ::XMLSchema::string< ACE_TCHAR > const& requirementName__,
                                             ::XMLSchema::string< ACE_TCHAR > const& resourceName__)
    : 
    ::XSCRT::Type (), 
    targetName_ (new ::XMLSchema::string< ACE_TCHAR > (targetName__)),
    requirementName_ (new ::XMLSchema::string< ACE_TCHAR > (requirementName__)),
    resourceName_ (new ::XMLSchema::string< ACE_TCHAR > (resourceName__)),
    regulator__ ()
    {
      targetName_->container (this);
      requirementName_->container (this);
      resourceName_->container (this);
    }

    ConnectionResourceDeploymentDescription::
    ConnectionResourceDeploymentDescription (::CIAO::Config_Handlers::ConnectionResourceDeploymentDescription const& s)
    :
    ::XSCRT::Type (),
    targetName_ (new ::XMLSchema::string< ACE_TCHAR > (*s.targetName_)),
    requirementName_ (new ::XMLSchema::string< ACE_TCHAR > (*s.requirementName_)),
    resourceName_ (new ::XMLSchema::string< ACE_TCHAR > (*s.resourceName_)),
    regulator__ ()
    {
      targetName_->container (this);
      requirementName_->container (this);
      resourceName_->container (this);
      {
        for (property_const_iterator i (s.property_.begin ());i != s.property_.end ();++i) add_property (*i);
      }
    }

    ::CIAO::Config_Handlers::ConnectionResourceDeploymentDescription& ConnectionResourceDeploymentDescription::
    operator= (::CIAO::Config_Handlers::ConnectionResourceDeploymentDescription const& s)
    {
      targetName (s.targetName ());

      requirementName (s.requirementName ());

      resourceName (s.resourceName ());

      property_.clear ();
      {
        for (property_const_iterator i (s.property_.begin ());i != s.property_.end ();++i) add_property (*i);
      }

      return *this;
    }


    // ConnectionResourceDeploymentDescription
    // 
    ::XMLSchema::string< ACE_TCHAR > const& ConnectionResourceDeploymentDescription::
    targetName () const
    {
      return *targetName_;
    }

    void ConnectionResourceDeploymentDescription::
    targetName (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *targetName_ = e;
    }

    // ConnectionResourceDeploymentDescription
    // 
    ::XMLSchema::string< ACE_TCHAR > const& ConnectionResourceDeploymentDescription::
    requirementName () const
    {
      return *requirementName_;
    }

    void ConnectionResourceDeploymentDescription::
    requirementName (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *requirementName_ = e;
    }

    // ConnectionResourceDeploymentDescription
    // 
    ::XMLSchema::string< ACE_TCHAR > const& ConnectionResourceDeploymentDescription::
    resourceName () const
    {
      return *resourceName_;
    }

    void ConnectionResourceDeploymentDescription::
    resourceName (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *resourceName_ = e;
    }

    // ConnectionResourceDeploymentDescription
    // 
    ConnectionResourceDeploymentDescription::property_iterator ConnectionResourceDeploymentDescription::
    begin_property ()
    {
      return property_.begin ();
    }

    ConnectionResourceDeploymentDescription::property_iterator ConnectionResourceDeploymentDescription::
    end_property ()
    {
      return property_.end ();
    }

    ConnectionResourceDeploymentDescription::property_const_iterator ConnectionResourceDeploymentDescription::
    begin_property () const
    {
      return property_.begin ();
    }

    ConnectionResourceDeploymentDescription::property_const_iterator ConnectionResourceDeploymentDescription::
    end_property () const
    {
      return property_.end ();
    }

    void ConnectionResourceDeploymentDescription::
    add_property (::CIAO::Config_Handlers::Property const& e)
    {
      property_.push_back (e);
    }

    size_t ConnectionResourceDeploymentDescription::
    count_property(void) const
    {
      return property_.size ();
    }


    // PlanConnectionDescription
    // 

    PlanConnectionDescription::
    PlanConnectionDescription (::XMLSchema::string< ACE_TCHAR > const& name__)
    : 
    ::XSCRT::Type (), 
    name_ (new ::XMLSchema::string< ACE_TCHAR > (name__)),
    regulator__ ()
    {
      name_->container (this);
    }

    PlanConnectionDescription::
    PlanConnectionDescription (::CIAO::Config_Handlers::PlanConnectionDescription const& s)
    :
    ::XSCRT::Type (),
    name_ (new ::XMLSchema::string< ACE_TCHAR > (*s.name_)),
    source_ (s.source_.get () ? new ::XMLSchema::string< ACE_TCHAR > (*s.source_) : 0),
    regulator__ ()
    {
      name_->container (this);
      if (source_.get ()) source_->container (this);
      {
        for (deployRequirement_const_iterator i (s.deployRequirement_.begin ());i != s.deployRequirement_.end ();++i) add_deployRequirement (*i);
      }

      {
        for (externalEndpoint_const_iterator i (s.externalEndpoint_.begin ());i != s.externalEndpoint_.end ();++i) add_externalEndpoint (*i);
      }

      {
        for (internalEndpoint_const_iterator i (s.internalEndpoint_.begin ());i != s.internalEndpoint_.end ();++i) add_internalEndpoint (*i);
      }

      {
        for (externalReference_const_iterator i (s.externalReference_.begin ());i != s.externalReference_.end ();++i) add_externalReference (*i);
      }

      {
        for (deployedResource_const_iterator i (s.deployedResource_.begin ());i != s.deployedResource_.end ();++i) add_deployedResource (*i);
      }
    }

    ::CIAO::Config_Handlers::PlanConnectionDescription& PlanConnectionDescription::
    operator= (::CIAO::Config_Handlers::PlanConnectionDescription const& s)
    {
      name (s.name ());

      if (s.source_.get ()) source (*(s.source_));
      else source_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (0);

      deployRequirement_.clear ();
      {
        for (deployRequirement_const_iterator i (s.deployRequirement_.begin ());i != s.deployRequirement_.end ();++i) add_deployRequirement (*i);
      }

      externalEndpoint_.clear ();
      {
        for (externalEndpoint_const_iterator i (s.externalEndpoint_.begin ());i != s.externalEndpoint_.end ();++i) add_externalEndpoint (*i);
      }

      internalEndpoint_.clear ();
      {
        for (internalEndpoint_const_iterator i (s.internalEndpoint_.begin ());i != s.internalEndpoint_.end ();++i) add_internalEndpoint (*i);
      }

      externalReference_.clear ();
      {
        for (externalReference_const_iterator i (s.externalReference_.begin ());i != s.externalReference_.end ();++i) add_externalReference (*i);
      }

      deployedResource_.clear ();
      {
        for (deployedResource_const_iterator i (s.deployedResource_.begin ());i != s.deployedResource_.end ();++i) add_deployedResource (*i);
      }

      return *this;
    }


    // PlanConnectionDescription
    // 
    ::XMLSchema::string< ACE_TCHAR > const& PlanConnectionDescription::
    name () const
    {
      return *name_;
    }

    void PlanConnectionDescription::
    name (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *name_ = e;
    }

    // PlanConnectionDescription
    // 
    bool PlanConnectionDescription::
    source_p () const
    {
      return source_.get () != 0;
    }

    ::XMLSchema::string< ACE_TCHAR > const& PlanConnectionDescription::
    source () const
    {
      return *source_;
    }

    void PlanConnectionDescription::
    source (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      if (source_.get ())
      {
        *source_ = e;
      }

      else
      {
        source_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
        source_->container (this);
      }
    }

    // PlanConnectionDescription
    // 
    PlanConnectionDescription::deployRequirement_iterator PlanConnectionDescription::
    begin_deployRequirement ()
    {
      return deployRequirement_.begin ();
    }

    PlanConnectionDescription::deployRequirement_iterator PlanConnectionDescription::
    end_deployRequirement ()
    {
      return deployRequirement_.end ();
    }

    PlanConnectionDescription::deployRequirement_const_iterator PlanConnectionDescription::
    begin_deployRequirement () const
    {
      return deployRequirement_.begin ();
    }

    PlanConnectionDescription::deployRequirement_const_iterator PlanConnectionDescription::
    end_deployRequirement () const
    {
      return deployRequirement_.end ();
    }

    void PlanConnectionDescription::
    add_deployRequirement (::CIAO::Config_Handlers::Requirement const& e)
    {
      deployRequirement_.push_back (e);
    }

    size_t PlanConnectionDescription::
    count_deployRequirement(void) const
    {
      return deployRequirement_.size ();
    }

    // PlanConnectionDescription
    // 
    PlanConnectionDescription::externalEndpoint_iterator PlanConnectionDescription::
    begin_externalEndpoint ()
    {
      return externalEndpoint_.begin ();
    }

    PlanConnectionDescription::externalEndpoint_iterator PlanConnectionDescription::
    end_externalEndpoint ()
    {
      return externalEndpoint_.end ();
    }

    PlanConnectionDescription::externalEndpoint_const_iterator PlanConnectionDescription::
    begin_externalEndpoint () const
    {
      return externalEndpoint_.begin ();
    }

    PlanConnectionDescription::externalEndpoint_const_iterator PlanConnectionDescription::
    end_externalEndpoint () const
    {
      return externalEndpoint_.end ();
    }

    void PlanConnectionDescription::
    add_externalEndpoint (::CIAO::Config_Handlers::ComponentExternalPortEndpoint const& e)
    {
      externalEndpoint_.push_back (e);
    }

    size_t PlanConnectionDescription::
    count_externalEndpoint(void) const
    {
      return externalEndpoint_.size ();
    }

    // PlanConnectionDescription
    // 
    PlanConnectionDescription::internalEndpoint_iterator PlanConnectionDescription::
    begin_internalEndpoint ()
    {
      return internalEndpoint_.begin ();
    }

    PlanConnectionDescription::internalEndpoint_iterator PlanConnectionDescription::
    end_internalEndpoint ()
    {
      return internalEndpoint_.end ();
    }

    PlanConnectionDescription::internalEndpoint_const_iterator PlanConnectionDescription::
    begin_internalEndpoint () const
    {
      return internalEndpoint_.begin ();
    }

    PlanConnectionDescription::internalEndpoint_const_iterator PlanConnectionDescription::
    end_internalEndpoint () const
    {
      return internalEndpoint_.end ();
    }

    void PlanConnectionDescription::
    add_internalEndpoint (::CIAO::Config_Handlers::PlanSubcomponentPortEndpoint const& e)
    {
      internalEndpoint_.push_back (e);
    }

    size_t PlanConnectionDescription::
    count_internalEndpoint(void) const
    {
      return internalEndpoint_.size ();
    }

    // PlanConnectionDescription
    // 
    PlanConnectionDescription::externalReference_iterator PlanConnectionDescription::
    begin_externalReference ()
    {
      return externalReference_.begin ();
    }

    PlanConnectionDescription::externalReference_iterator PlanConnectionDescription::
    end_externalReference ()
    {
      return externalReference_.end ();
    }

    PlanConnectionDescription::externalReference_const_iterator PlanConnectionDescription::
    begin_externalReference () const
    {
      return externalReference_.begin ();
    }

    PlanConnectionDescription::externalReference_const_iterator PlanConnectionDescription::
    end_externalReference () const
    {
      return externalReference_.end ();
    }

    void PlanConnectionDescription::
    add_externalReference (::CIAO::Config_Handlers::ExternalReferenceEndpoint const& e)
    {
      externalReference_.push_back (e);
    }

    size_t PlanConnectionDescription::
    count_externalReference(void) const
    {
      return externalReference_.size ();
    }

    // PlanConnectionDescription
    // 
    PlanConnectionDescription::deployedResource_iterator PlanConnectionDescription::
    begin_deployedResource ()
    {
      return deployedResource_.begin ();
    }

    PlanConnectionDescription::deployedResource_iterator PlanConnectionDescription::
    end_deployedResource ()
    {
      return deployedResource_.end ();
    }

    PlanConnectionDescription::deployedResource_const_iterator PlanConnectionDescription::
    begin_deployedResource () const
    {
      return deployedResource_.begin ();
    }

    PlanConnectionDescription::deployedResource_const_iterator PlanConnectionDescription::
    end_deployedResource () const
    {
      return deployedResource_.end ();
    }

    void PlanConnectionDescription::
    add_deployedResource (::CIAO::Config_Handlers::ConnectionResourceDeploymentDescription const& e)
    {
      deployedResource_.push_back (e);
    }

    size_t PlanConnectionDescription::
    count_deployedResource(void) const
    {
      return deployedResource_.size ();
    }


    // ImplementationDependency
    // 

    ImplementationDependency::
    ImplementationDependency (::XMLSchema::string< ACE_TCHAR > const& requiredType__)
    : 
    ::XSCRT::Type (), 
    requiredType_ (new ::XMLSchema::string< ACE_TCHAR > (requiredType__)),
    regulator__ ()
    {
      requiredType_->container (this);
    }

    ImplementationDependency::
    ImplementationDependency (::CIAO::Config_Handlers::ImplementationDependency const& s)
    :
    ::XSCRT::Type (),
    requiredType_ (new ::XMLSchema::string< ACE_TCHAR > (*s.requiredType_)),
    regulator__ ()
    {
      requiredType_->container (this);
    }

    ::CIAO::Config_Handlers::ImplementationDependency& ImplementationDependency::
    operator= (::CIAO::Config_Handlers::ImplementationDependency const& s)
    {
      requiredType (s.requiredType ());

      return *this;
    }


    // ImplementationDependency
    // 
    ::XMLSchema::string< ACE_TCHAR > const& ImplementationDependency::
    requiredType () const
    {
      return *requiredType_;
    }

    void ImplementationDependency::
    requiredType (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *requiredType_ = e;
    }


    // Capability
    // 

    Capability::
    Capability (::XMLSchema::string< ACE_TCHAR > const& name__)
    : 
    ::XSCRT::Type (), 
    name_ (new ::XMLSchema::string< ACE_TCHAR > (name__)),
    regulator__ ()
    {
      name_->container (this);
    }

    Capability::
    Capability (::CIAO::Config_Handlers::Capability const& s)
    :
    ::XSCRT::Type (),
    name_ (new ::XMLSchema::string< ACE_TCHAR > (*s.name_)),
    regulator__ ()
    {
      name_->container (this);
      {
        for (resourceType_const_iterator i (s.resourceType_.begin ());i != s.resourceType_.end ();++i) add_resourceType (*i);
      }

      {
        for (property_const_iterator i (s.property_.begin ());i != s.property_.end ();++i) add_property (*i);
      }
    }

    ::CIAO::Config_Handlers::Capability& Capability::
    operator= (::CIAO::Config_Handlers::Capability const& s)
    {
      name (s.name ());

      resourceType_.clear ();
      {
        for (resourceType_const_iterator i (s.resourceType_.begin ());i != s.resourceType_.end ();++i) add_resourceType (*i);
      }

      property_.clear ();
      {
        for (property_const_iterator i (s.property_.begin ());i != s.property_.end ();++i) add_property (*i);
      }

      return *this;
    }


    // Capability
    // 
    ::XMLSchema::string< ACE_TCHAR > const& Capability::
    name () const
    {
      return *name_;
    }

    void Capability::
    name (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *name_ = e;
    }

    // Capability
    // 
    Capability::resourceType_iterator Capability::
    begin_resourceType ()
    {
      return resourceType_.begin ();
    }

    Capability::resourceType_iterator Capability::
    end_resourceType ()
    {
      return resourceType_.end ();
    }

    Capability::resourceType_const_iterator Capability::
    begin_resourceType () const
    {
      return resourceType_.begin ();
    }

    Capability::resourceType_const_iterator Capability::
    end_resourceType () const
    {
      return resourceType_.end ();
    }

    void Capability::
    add_resourceType (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      resourceType_.push_back (e);
    }

    size_t Capability::
    count_resourceType(void) const
    {
      return resourceType_.size ();
    }

    // Capability
    // 
    Capability::property_iterator Capability::
    begin_property ()
    {
      return property_.begin ();
    }

    Capability::property_iterator Capability::
    end_property ()
    {
      return property_.end ();
    }

    Capability::property_const_iterator Capability::
    begin_property () const
    {
      return property_.begin ();
    }

    Capability::property_const_iterator Capability::
    end_property () const
    {
      return property_.end ();
    }

    void Capability::
    add_property (::CIAO::Config_Handlers::SatisfierProperty const& e)
    {
      property_.push_back (e);
    }

    size_t Capability::
    count_property(void) const
    {
      return property_.size ();
    }


    // ImplementationRequirement
    // 

    ImplementationRequirement::
    ImplementationRequirement (::XMLSchema::string< ACE_TCHAR > const& resourceType__,
                               ::XMLSchema::string< ACE_TCHAR > const& name__)
    : 
    ::XSCRT::Type (), 
    resourceType_ (new ::XMLSchema::string< ACE_TCHAR > (resourceType__)),
    name_ (new ::XMLSchema::string< ACE_TCHAR > (name__)),
    regulator__ ()
    {
      resourceType_->container (this);
      name_->container (this);
    }

    ImplementationRequirement::
    ImplementationRequirement (::CIAO::Config_Handlers::ImplementationRequirement const& s)
    :
    ::XSCRT::Type (),
    resourceUsage_ (s.resourceUsage_.get () ? new ::CIAO::Config_Handlers::ResourceUsageKind (*s.resourceUsage_) : 0),
    resourcePort_ (s.resourcePort_.get () ? new ::XMLSchema::string< ACE_TCHAR > (*s.resourcePort_) : 0),
    componentPort_ (s.componentPort_.get () ? new ::XMLSchema::string< ACE_TCHAR > (*s.componentPort_) : 0),
    resourceType_ (new ::XMLSchema::string< ACE_TCHAR > (*s.resourceType_)),
    name_ (new ::XMLSchema::string< ACE_TCHAR > (*s.name_)),
    regulator__ ()
    {
      if (resourceUsage_.get ()) resourceUsage_->container (this);
      if (resourcePort_.get ()) resourcePort_->container (this);
      if (componentPort_.get ()) componentPort_->container (this);
      resourceType_->container (this);
      name_->container (this);
      {
        for (property_const_iterator i (s.property_.begin ());i != s.property_.end ();++i) add_property (*i);
      }
    }

    ::CIAO::Config_Handlers::ImplementationRequirement& ImplementationRequirement::
    operator= (::CIAO::Config_Handlers::ImplementationRequirement const& s)
    {
      if (s.resourceUsage_.get ()) resourceUsage (*(s.resourceUsage_));
      else resourceUsage_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ResourceUsageKind > (0);

      if (s.resourcePort_.get ()) resourcePort (*(s.resourcePort_));
      else resourcePort_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (0);

      if (s.componentPort_.get ()) componentPort (*(s.componentPort_));
      else componentPort_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (0);

      resourceType (s.resourceType ());

      name (s.name ());

      property_.clear ();
      {
        for (property_const_iterator i (s.property_.begin ());i != s.property_.end ();++i) add_property (*i);
      }

      return *this;
    }


    // ImplementationRequirement
    // 
    bool ImplementationRequirement::
    resourceUsage_p () const
    {
      return resourceUsage_.get () != 0;
    }

    ::CIAO::Config_Handlers::ResourceUsageKind const& ImplementationRequirement::
    resourceUsage () const
    {
      return *resourceUsage_;
    }

    void ImplementationRequirement::
    resourceUsage (::CIAO::Config_Handlers::ResourceUsageKind const& e)
    {
      if (resourceUsage_.get ())
      {
        *resourceUsage_ = e;
      }

      else
      {
        resourceUsage_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ResourceUsageKind > (new ::CIAO::Config_Handlers::ResourceUsageKind (e));
        resourceUsage_->container (this);
      }
    }

    // ImplementationRequirement
    // 
    bool ImplementationRequirement::
    resourcePort_p () const
    {
      return resourcePort_.get () != 0;
    }

    ::XMLSchema::string< ACE_TCHAR > const& ImplementationRequirement::
    resourcePort () const
    {
      return *resourcePort_;
    }

    void ImplementationRequirement::
    resourcePort (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      if (resourcePort_.get ())
      {
        *resourcePort_ = e;
      }

      else
      {
        resourcePort_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
        resourcePort_->container (this);
      }
    }

    // ImplementationRequirement
    // 
    bool ImplementationRequirement::
    componentPort_p () const
    {
      return componentPort_.get () != 0;
    }

    ::XMLSchema::string< ACE_TCHAR > const& ImplementationRequirement::
    componentPort () const
    {
      return *componentPort_;
    }

    void ImplementationRequirement::
    componentPort (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      if (componentPort_.get ())
      {
        *componentPort_ = e;
      }

      else
      {
        componentPort_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
        componentPort_->container (this);
      }
    }

    // ImplementationRequirement
    // 
    ::XMLSchema::string< ACE_TCHAR > const& ImplementationRequirement::
    resourceType () const
    {
      return *resourceType_;
    }

    void ImplementationRequirement::
    resourceType (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *resourceType_ = e;
    }

    // ImplementationRequirement
    // 
    ::XMLSchema::string< ACE_TCHAR > const& ImplementationRequirement::
    name () const
    {
      return *name_;
    }

    void ImplementationRequirement::
    name (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *name_ = e;
    }

    // ImplementationRequirement
    // 
    ImplementationRequirement::property_iterator ImplementationRequirement::
    begin_property ()
    {
      return property_.begin ();
    }

    ImplementationRequirement::property_iterator ImplementationRequirement::
    end_property ()
    {
      return property_.end ();
    }

    ImplementationRequirement::property_const_iterator ImplementationRequirement::
    begin_property () const
    {
      return property_.begin ();
    }

    ImplementationRequirement::property_const_iterator ImplementationRequirement::
    end_property () const
    {
      return property_.end ();
    }

    void ImplementationRequirement::
    add_property (::CIAO::Config_Handlers::Property const& e)
    {
      property_.push_back (e);
    }

    size_t ImplementationRequirement::
    count_property(void) const
    {
      return property_.size ();
    }


    // ComponentPackageReference
    // 

    ComponentPackageReference::
    ComponentPackageReference (::XMLSchema::string< ACE_TCHAR > const& requiredType__)
    : 
    ::XSCRT::Type (), 
    requiredType_ (new ::XMLSchema::string< ACE_TCHAR > (requiredType__)),
    regulator__ ()
    {
      requiredType_->container (this);
    }

    ComponentPackageReference::
    ComponentPackageReference (::CIAO::Config_Handlers::ComponentPackageReference const& s)
    :
    ::XSCRT::Type (),
    requiredUUID_ (s.requiredUUID_.get () ? new ::XMLSchema::string< ACE_TCHAR > (*s.requiredUUID_) : 0),
    requiredName_ (s.requiredName_.get () ? new ::XMLSchema::string< ACE_TCHAR > (*s.requiredName_) : 0),
    requiredType_ (new ::XMLSchema::string< ACE_TCHAR > (*s.requiredType_)),
    regulator__ ()
    {
      if (requiredUUID_.get ()) requiredUUID_->container (this);
      if (requiredName_.get ()) requiredName_->container (this);
      requiredType_->container (this);
    }

    ::CIAO::Config_Handlers::ComponentPackageReference& ComponentPackageReference::
    operator= (::CIAO::Config_Handlers::ComponentPackageReference const& s)
    {
      if (s.requiredUUID_.get ()) requiredUUID (*(s.requiredUUID_));
      else requiredUUID_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (0);

      if (s.requiredName_.get ()) requiredName (*(s.requiredName_));
      else requiredName_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (0);

      requiredType (s.requiredType ());

      return *this;
    }


    // ComponentPackageReference
    // 
    bool ComponentPackageReference::
    requiredUUID_p () const
    {
      return requiredUUID_.get () != 0;
    }

    ::XMLSchema::string< ACE_TCHAR > const& ComponentPackageReference::
    requiredUUID () const
    {
      return *requiredUUID_;
    }

    void ComponentPackageReference::
    requiredUUID (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      if (requiredUUID_.get ())
      {
        *requiredUUID_ = e;
      }

      else
      {
        requiredUUID_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
        requiredUUID_->container (this);
      }
    }

    // ComponentPackageReference
    // 
    bool ComponentPackageReference::
    requiredName_p () const
    {
      return requiredName_.get () != 0;
    }

    ::XMLSchema::string< ACE_TCHAR > const& ComponentPackageReference::
    requiredName () const
    {
      return *requiredName_;
    }

    void ComponentPackageReference::
    requiredName (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      if (requiredName_.get ())
      {
        *requiredName_ = e;
      }

      else
      {
        requiredName_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
        requiredName_->container (this);
      }
    }

    // ComponentPackageReference
    // 
    ::XMLSchema::string< ACE_TCHAR > const& ComponentPackageReference::
    requiredType () const
    {
      return *requiredType_;
    }

    void ComponentPackageReference::
    requiredType (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *requiredType_ = e;
    }


    // SubcomponentPortEndpoint
    // 

    SubcomponentPortEndpoint::
    SubcomponentPortEndpoint (::XMLSchema::string< ACE_TCHAR > const& portName__,
                              ::XMLSchema::IDREF< ACE_TCHAR > const& instance__)
    : 
    ::XSCRT::Type (), 
    portName_ (new ::XMLSchema::string< ACE_TCHAR > (portName__)),
    instance_ (new ::XMLSchema::IDREF< ACE_TCHAR > (instance__)),
    regulator__ ()
    {
      portName_->container (this);
      instance_->container (this);
    }

    SubcomponentPortEndpoint::
    SubcomponentPortEndpoint (::CIAO::Config_Handlers::SubcomponentPortEndpoint const& s)
    :
    ::XSCRT::Type (),
    portName_ (new ::XMLSchema::string< ACE_TCHAR > (*s.portName_)),
    instance_ (new ::XMLSchema::IDREF< ACE_TCHAR > (*s.instance_)),
    regulator__ ()
    {
      portName_->container (this);
      instance_->container (this);
    }

    ::CIAO::Config_Handlers::SubcomponentPortEndpoint& SubcomponentPortEndpoint::
    operator= (::CIAO::Config_Handlers::SubcomponentPortEndpoint const& s)
    {
      portName (s.portName ());

      instance (s.instance ());

      return *this;
    }


    // SubcomponentPortEndpoint
    // 
    ::XMLSchema::string< ACE_TCHAR > const& SubcomponentPortEndpoint::
    portName () const
    {
      return *portName_;
    }

    void SubcomponentPortEndpoint::
    portName (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *portName_ = e;
    }

    // SubcomponentPortEndpoint
    // 
    ::XMLSchema::IDREF< ACE_TCHAR > const& SubcomponentPortEndpoint::
    instance () const
    {
      return *instance_;
    }

    void SubcomponentPortEndpoint::
    instance (::XMLSchema::IDREF< ACE_TCHAR > const& e)
    {
      *instance_ = e;
    }


    // AssemblyConnectionDescription
    // 

    AssemblyConnectionDescription::
    AssemblyConnectionDescription (::XMLSchema::string< ACE_TCHAR > const& name__)
    : 
    ::XSCRT::Type (), 
    name_ (new ::XMLSchema::string< ACE_TCHAR > (name__)),
    regulator__ ()
    {
      name_->container (this);
    }

    AssemblyConnectionDescription::
    AssemblyConnectionDescription (::CIAO::Config_Handlers::AssemblyConnectionDescription const& s)
    :
    ::XSCRT::Type (),
    name_ (new ::XMLSchema::string< ACE_TCHAR > (*s.name_)),
    regulator__ ()
    {
      name_->container (this);
      {
        for (deployRequirement_const_iterator i (s.deployRequirement_.begin ());i != s.deployRequirement_.end ();++i) add_deployRequirement (*i);
      }

      {
        for (internalEndpoint_const_iterator i (s.internalEndpoint_.begin ());i != s.internalEndpoint_.end ();++i) add_internalEndpoint (*i);
      }

      {
        for (externalEndpoint_const_iterator i (s.externalEndpoint_.begin ());i != s.externalEndpoint_.end ();++i) add_externalEndpoint (*i);
      }

      {
        for (externalReference_const_iterator i (s.externalReference_.begin ());i != s.externalReference_.end ();++i) add_externalReference (*i);
      }
    }

    ::CIAO::Config_Handlers::AssemblyConnectionDescription& AssemblyConnectionDescription::
    operator= (::CIAO::Config_Handlers::AssemblyConnectionDescription const& s)
    {
      name (s.name ());

      deployRequirement_.clear ();
      {
        for (deployRequirement_const_iterator i (s.deployRequirement_.begin ());i != s.deployRequirement_.end ();++i) add_deployRequirement (*i);
      }

      internalEndpoint_.clear ();
      {
        for (internalEndpoint_const_iterator i (s.internalEndpoint_.begin ());i != s.internalEndpoint_.end ();++i) add_internalEndpoint (*i);
      }

      externalEndpoint_.clear ();
      {
        for (externalEndpoint_const_iterator i (s.externalEndpoint_.begin ());i != s.externalEndpoint_.end ();++i) add_externalEndpoint (*i);
      }

      externalReference_.clear ();
      {
        for (externalReference_const_iterator i (s.externalReference_.begin ());i != s.externalReference_.end ();++i) add_externalReference (*i);
      }

      return *this;
    }


    // AssemblyConnectionDescription
    // 
    ::XMLSchema::string< ACE_TCHAR > const& AssemblyConnectionDescription::
    name () const
    {
      return *name_;
    }

    void AssemblyConnectionDescription::
    name (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *name_ = e;
    }

    // AssemblyConnectionDescription
    // 
    AssemblyConnectionDescription::deployRequirement_iterator AssemblyConnectionDescription::
    begin_deployRequirement ()
    {
      return deployRequirement_.begin ();
    }

    AssemblyConnectionDescription::deployRequirement_iterator AssemblyConnectionDescription::
    end_deployRequirement ()
    {
      return deployRequirement_.end ();
    }

    AssemblyConnectionDescription::deployRequirement_const_iterator AssemblyConnectionDescription::
    begin_deployRequirement () const
    {
      return deployRequirement_.begin ();
    }

    AssemblyConnectionDescription::deployRequirement_const_iterator AssemblyConnectionDescription::
    end_deployRequirement () const
    {
      return deployRequirement_.end ();
    }

    void AssemblyConnectionDescription::
    add_deployRequirement (::CIAO::Config_Handlers::Requirement const& e)
    {
      deployRequirement_.push_back (e);
    }

    size_t AssemblyConnectionDescription::
    count_deployRequirement(void) const
    {
      return deployRequirement_.size ();
    }

    // AssemblyConnectionDescription
    // 
    AssemblyConnectionDescription::internalEndpoint_iterator AssemblyConnectionDescription::
    begin_internalEndpoint ()
    {
      return internalEndpoint_.begin ();
    }

    AssemblyConnectionDescription::internalEndpoint_iterator AssemblyConnectionDescription::
    end_internalEndpoint ()
    {
      return internalEndpoint_.end ();
    }

    AssemblyConnectionDescription::internalEndpoint_const_iterator AssemblyConnectionDescription::
    begin_internalEndpoint () const
    {
      return internalEndpoint_.begin ();
    }

    AssemblyConnectionDescription::internalEndpoint_const_iterator AssemblyConnectionDescription::
    end_internalEndpoint () const
    {
      return internalEndpoint_.end ();
    }

    void AssemblyConnectionDescription::
    add_internalEndpoint (::CIAO::Config_Handlers::SubcomponentPortEndpoint const& e)
    {
      internalEndpoint_.push_back (e);
    }

    size_t AssemblyConnectionDescription::
    count_internalEndpoint(void) const
    {
      return internalEndpoint_.size ();
    }

    // AssemblyConnectionDescription
    // 
    AssemblyConnectionDescription::externalEndpoint_iterator AssemblyConnectionDescription::
    begin_externalEndpoint ()
    {
      return externalEndpoint_.begin ();
    }

    AssemblyConnectionDescription::externalEndpoint_iterator AssemblyConnectionDescription::
    end_externalEndpoint ()
    {
      return externalEndpoint_.end ();
    }

    AssemblyConnectionDescription::externalEndpoint_const_iterator AssemblyConnectionDescription::
    begin_externalEndpoint () const
    {
      return externalEndpoint_.begin ();
    }

    AssemblyConnectionDescription::externalEndpoint_const_iterator AssemblyConnectionDescription::
    end_externalEndpoint () const
    {
      return externalEndpoint_.end ();
    }

    void AssemblyConnectionDescription::
    add_externalEndpoint (::CIAO::Config_Handlers::ComponentExternalPortEndpoint const& e)
    {
      externalEndpoint_.push_back (e);
    }

    size_t AssemblyConnectionDescription::
    count_externalEndpoint(void) const
    {
      return externalEndpoint_.size ();
    }

    // AssemblyConnectionDescription
    // 
    AssemblyConnectionDescription::externalReference_iterator AssemblyConnectionDescription::
    begin_externalReference ()
    {
      return externalReference_.begin ();
    }

    AssemblyConnectionDescription::externalReference_iterator AssemblyConnectionDescription::
    end_externalReference ()
    {
      return externalReference_.end ();
    }

    AssemblyConnectionDescription::externalReference_const_iterator AssemblyConnectionDescription::
    begin_externalReference () const
    {
      return externalReference_.begin ();
    }

    AssemblyConnectionDescription::externalReference_const_iterator AssemblyConnectionDescription::
    end_externalReference () const
    {
      return externalReference_.end ();
    }

    void AssemblyConnectionDescription::
    add_externalReference (::CIAO::Config_Handlers::ExternalReferenceEndpoint const& e)
    {
      externalReference_.push_back (e);
    }

    size_t AssemblyConnectionDescription::
    count_externalReference(void) const
    {
      return externalReference_.size ();
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    // TCKind
    //

    TCKind::
    TCKind (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    : ::XSCRT::Type (e)
    {
      ::std::basic_string< ACE_TCHAR > v (e.value ());

      if (v == "tk_null") v_ = tk_null_l;
      else if (v == "tk_void") v_ = tk_void_l;
      else if (v == "tk_short") v_ = tk_short_l;
      else if (v == "tk_long") v_ = tk_long_l;
      else if (v == "tk_ushort") v_ = tk_ushort_l;
      else if (v == "tk_ulong") v_ = tk_ulong_l;
      else if (v == "tk_float") v_ = tk_float_l;
      else if (v == "tk_double") v_ = tk_double_l;
      else if (v == "tk_boolean") v_ = tk_boolean_l;
      else if (v == "tk_char") v_ = tk_char_l;
      else if (v == "tk_octet") v_ = tk_octet_l;
      else if (v == "tk_any") v_ = tk_any_l;
      else if (v == "tk_TypeCode") v_ = tk_TypeCode_l;
      else if (v == "tk_Principal") v_ = tk_Principal_l;
      else if (v == "tk_objref") v_ = tk_objref_l;
      else if (v == "tk_struct") v_ = tk_struct_l;
      else if (v == "tk_union") v_ = tk_union_l;
      else if (v == "tk_enum") v_ = tk_enum_l;
      else if (v == "tk_string") v_ = tk_string_l;
      else if (v == "tk_sequence") v_ = tk_sequence_l;
      else if (v == "tk_array") v_ = tk_array_l;
      else if (v == "tk_alias") v_ = tk_alias_l;
      else if (v == "tk_except") v_ = tk_except_l;
      else if (v == "tk_longlong") v_ = tk_longlong_l;
      else if (v == "tk_ulonglong") v_ = tk_ulonglong_l;
      else if (v == "tk_longdouble") v_ = tk_longdouble_l;
      else if (v == "tk_wchar") v_ = tk_wchar_l;
      else if (v == "tk_wstring") v_ = tk_wstring_l;
      else if (v == "tk_wfixed") v_ = tk_wfixed_l;
      else if (v == "tk_value") v_ = tk_value_l;
      else if (v == "tk_value_box") v_ = tk_value_box_l;
      else if (v == "tk_native") v_ = tk_native_l;
      else if (v == "tk_abstract_interface") v_ = tk_abstract_interface_l;
      else if (v == "tk_local_interface") v_ = tk_local_interface_l;
      else if (v == "tk_component") v_ = tk_component_l;
      else if (v == "tk_home") v_ = tk_home_l;
      else if (v == "tk_event") v_ = tk_event_l;
      else 
      {
      }
    }

    TCKind::
    TCKind (::XSCRT::XML::Attribute< ACE_TCHAR > const& a)
    : ::XSCRT::Type (a)
    {
      ::std::basic_string< ACE_TCHAR > v (a.value ());

      if (v == "tk_null") v_ = tk_null_l;
      else if (v == "tk_void") v_ = tk_void_l;
      else if (v == "tk_short") v_ = tk_short_l;
      else if (v == "tk_long") v_ = tk_long_l;
      else if (v == "tk_ushort") v_ = tk_ushort_l;
      else if (v == "tk_ulong") v_ = tk_ulong_l;
      else if (v == "tk_float") v_ = tk_float_l;
      else if (v == "tk_double") v_ = tk_double_l;
      else if (v == "tk_boolean") v_ = tk_boolean_l;
      else if (v == "tk_char") v_ = tk_char_l;
      else if (v == "tk_octet") v_ = tk_octet_l;
      else if (v == "tk_any") v_ = tk_any_l;
      else if (v == "tk_TypeCode") v_ = tk_TypeCode_l;
      else if (v == "tk_Principal") v_ = tk_Principal_l;
      else if (v == "tk_objref") v_ = tk_objref_l;
      else if (v == "tk_struct") v_ = tk_struct_l;
      else if (v == "tk_union") v_ = tk_union_l;
      else if (v == "tk_enum") v_ = tk_enum_l;
      else if (v == "tk_string") v_ = tk_string_l;
      else if (v == "tk_sequence") v_ = tk_sequence_l;
      else if (v == "tk_array") v_ = tk_array_l;
      else if (v == "tk_alias") v_ = tk_alias_l;
      else if (v == "tk_except") v_ = tk_except_l;
      else if (v == "tk_longlong") v_ = tk_longlong_l;
      else if (v == "tk_ulonglong") v_ = tk_ulonglong_l;
      else if (v == "tk_longdouble") v_ = tk_longdouble_l;
      else if (v == "tk_wchar") v_ = tk_wchar_l;
      else if (v == "tk_wstring") v_ = tk_wstring_l;
      else if (v == "tk_wfixed") v_ = tk_wfixed_l;
      else if (v == "tk_value") v_ = tk_value_l;
      else if (v == "tk_value_box") v_ = tk_value_box_l;
      else if (v == "tk_native") v_ = tk_native_l;
      else if (v == "tk_abstract_interface") v_ = tk_abstract_interface_l;
      else if (v == "tk_local_interface") v_ = tk_local_interface_l;
      else if (v == "tk_component") v_ = tk_component_l;
      else if (v == "tk_home") v_ = tk_home_l;
      else if (v == "tk_event") v_ = tk_event_l;
      else 
      {
      }
    }

    TCKind const TCKind::tk_null (TCKind::tk_null_l);
    TCKind const TCKind::tk_void (TCKind::tk_void_l);
    TCKind const TCKind::tk_short (TCKind::tk_short_l);
    TCKind const TCKind::tk_long (TCKind::tk_long_l);
    TCKind const TCKind::tk_ushort (TCKind::tk_ushort_l);
    TCKind const TCKind::tk_ulong (TCKind::tk_ulong_l);
    TCKind const TCKind::tk_float (TCKind::tk_float_l);
    TCKind const TCKind::tk_double (TCKind::tk_double_l);
    TCKind const TCKind::tk_boolean (TCKind::tk_boolean_l);
    TCKind const TCKind::tk_char (TCKind::tk_char_l);
    TCKind const TCKind::tk_octet (TCKind::tk_octet_l);
    TCKind const TCKind::tk_any (TCKind::tk_any_l);
    TCKind const TCKind::tk_TypeCode (TCKind::tk_TypeCode_l);
    TCKind const TCKind::tk_Principal (TCKind::tk_Principal_l);
    TCKind const TCKind::tk_objref (TCKind::tk_objref_l);
    TCKind const TCKind::tk_struct (TCKind::tk_struct_l);
    TCKind const TCKind::tk_union (TCKind::tk_union_l);
    TCKind const TCKind::tk_enum (TCKind::tk_enum_l);
    TCKind const TCKind::tk_string (TCKind::tk_string_l);
    TCKind const TCKind::tk_sequence (TCKind::tk_sequence_l);
    TCKind const TCKind::tk_array (TCKind::tk_array_l);
    TCKind const TCKind::tk_alias (TCKind::tk_alias_l);
    TCKind const TCKind::tk_except (TCKind::tk_except_l);
    TCKind const TCKind::tk_longlong (TCKind::tk_longlong_l);
    TCKind const TCKind::tk_ulonglong (TCKind::tk_ulonglong_l);
    TCKind const TCKind::tk_longdouble (TCKind::tk_longdouble_l);
    TCKind const TCKind::tk_wchar (TCKind::tk_wchar_l);
    TCKind const TCKind::tk_wstring (TCKind::tk_wstring_l);
    TCKind const TCKind::tk_wfixed (TCKind::tk_wfixed_l);
    TCKind const TCKind::tk_value (TCKind::tk_value_l);
    TCKind const TCKind::tk_value_box (TCKind::tk_value_box_l);
    TCKind const TCKind::tk_native (TCKind::tk_native_l);
    TCKind const TCKind::tk_abstract_interface (TCKind::tk_abstract_interface_l);
    TCKind const TCKind::tk_local_interface (TCKind::tk_local_interface_l);
    TCKind const TCKind::tk_component (TCKind::tk_component_l);
    TCKind const TCKind::tk_home (TCKind::tk_home_l);
    TCKind const TCKind::tk_event (TCKind::tk_event_l);

    // DataType
    //

    DataType::
    DataType (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "kind")
        {
          kind_ = ::std::auto_ptr< ::CIAO::Config_Handlers::TCKind > (new ::CIAO::Config_Handlers::TCKind (e));
          kind_->container (this);
        }

        else if (n == "enum")
        {
          ::CIAO::Config_Handlers::EnumType t (e);
          enum_ (t);
        }

        else 
        {
        }
      }
    }

    // DataValue
    //

    DataValue::
    DataValue (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "short")
        {
          ::XMLSchema::short_ t (e);
          add_short (t);
        }

        else if (n == "long")
        {
          ::XMLSchema::int_ t (e);
          add_long (t);
        }

        else if (n == "ushort")
        {
          ::XMLSchema::unsignedShort t (e);
          add_ushort (t);
        }

        else if (n == "ulong")
        {
          ::XMLSchema::unsignedInt t (e);
          add_ulong (t);
        }

        else if (n == "float")
        {
          ::XMLSchema::float_ t (e);
          add_float (t);
        }

        else if (n == "double")
        {
          ::XMLSchema::double_ t (e);
          add_double (t);
        }

        else if (n == "boolean")
        {
          ::XMLSchema::boolean t (e);
          add_boolean (t);
        }

        else if (n == "octet")
        {
          ::XMLSchema::unsignedByte t (e);
          add_octet (t);
        }

        else if (n == "enum")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          add_enum (t);
        }

        else if (n == "string")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          add_string (t);
        }

        else if (n == "longlong")
        {
          ::XMLSchema::long_ t (e);
          add_longlong (t);
        }

        else if (n == "ulonglong")
        {
          ::XMLSchema::unsignedLong t (e);
          add_ulonglong (t);
        }

        else if (n == "longdouble")
        {
          ::XMLSchema::double_ t (e);
          add_longdouble (t);
        }

        else 
        {
        }
      }
    }

    // EnumType
    //

    EnumType::
    EnumType (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "name")
        {
          name_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          name_->container (this);
        }

        else if (n == "typeId")
        {
          typeId_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          typeId_->container (this);
        }

        else if (n == "member")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          add_member (t);
        }

        else 
        {
        }
      }
    }

    // Any
    //

    Any::
    Any (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "type")
        {
          type_ = ::std::auto_ptr< ::CIAO::Config_Handlers::DataType > (new ::CIAO::Config_Handlers::DataType (e));
          type_->container (this);
        }

        else if (n == "value")
        {
          value_ = ::std::auto_ptr< ::CIAO::Config_Handlers::DataValue > (new ::CIAO::Config_Handlers::DataValue (e));
          value_->container (this);
        }

        else 
        {
        }
      }
    }

    // Property
    //

    Property::
    Property (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "name")
        {
          name_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          name_->container (this);
        }

        else if (n == "value")
        {
          value_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Any > (new ::CIAO::Config_Handlers::Any (e));
          value_->container (this);
        }

        else 
        {
        }
      }
    }

    // SatisfierPropertyKind
    //

    SatisfierPropertyKind::
    SatisfierPropertyKind (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    : ::XSCRT::Type (e)
    {
      ::std::basic_string< ACE_TCHAR > v (e.value ());

      if (v == "Quantity") v_ = Quantity_l;
      else if (v == "Capacity") v_ = Capacity_l;
      else if (v == "Minimum") v_ = Minimum_l;
      else if (v == "Maximum") v_ = Maximum_l;
      else if (v == "Attribute") v_ = Attribute_l;
      else if (v == "Selection") v_ = Selection_l;
      else 
      {
      }
    }

    SatisfierPropertyKind::
    SatisfierPropertyKind (::XSCRT::XML::Attribute< ACE_TCHAR > const& a)
    : ::XSCRT::Type (a)
    {
      ::std::basic_string< ACE_TCHAR > v (a.value ());

      if (v == "Quantity") v_ = Quantity_l;
      else if (v == "Capacity") v_ = Capacity_l;
      else if (v == "Minimum") v_ = Minimum_l;
      else if (v == "Maximum") v_ = Maximum_l;
      else if (v == "Attribute") v_ = Attribute_l;
      else if (v == "Selection") v_ = Selection_l;
      else 
      {
      }
    }

    SatisfierPropertyKind const SatisfierPropertyKind::Quantity (SatisfierPropertyKind::Quantity_l);
    SatisfierPropertyKind const SatisfierPropertyKind::Capacity (SatisfierPropertyKind::Capacity_l);
    SatisfierPropertyKind const SatisfierPropertyKind::Minimum (SatisfierPropertyKind::Minimum_l);
    SatisfierPropertyKind const SatisfierPropertyKind::Maximum (SatisfierPropertyKind::Maximum_l);
    SatisfierPropertyKind const SatisfierPropertyKind::Attribute (SatisfierPropertyKind::Attribute_l);
    SatisfierPropertyKind const SatisfierPropertyKind::Selection (SatisfierPropertyKind::Selection_l);

    // SatisfierProperty
    //

    SatisfierProperty::
    SatisfierProperty (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "name")
        {
          name_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          name_->container (this);
        }

        else if (n == "kind")
        {
          kind_ = ::std::auto_ptr< ::CIAO::Config_Handlers::SatisfierPropertyKind > (new ::CIAO::Config_Handlers::SatisfierPropertyKind (e));
          kind_->container (this);
        }

        else if (n == "dynamic")
        {
          dynamic_ = ::std::auto_ptr< ::XMLSchema::boolean > (new ::XMLSchema::boolean (e));
          dynamic_->container (this);
        }

        else if (n == "value")
        {
          value_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Any > (new ::CIAO::Config_Handlers::Any (e));
          value_->container (this);
        }

        else 
        {
        }
      }
    }

    // Resource
    //

    Resource::
    Resource (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "name")
        {
          name_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          name_->container (this);
        }

        else if (n == "resourceType")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          add_resourceType (t);
        }

        else if (n == "property")
        {
          ::CIAO::Config_Handlers::SatisfierProperty t (e);
          add_property (t);
        }

        else 
        {
        }
      }
    }

    // Requirement
    //

    Requirement::
    Requirement (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "resourceType")
        {
          resourceType_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          resourceType_->container (this);
        }

        else if (n == "name")
        {
          name_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          name_->container (this);
        }

        else if (n == "property")
        {
          ::CIAO::Config_Handlers::Property t (e);
          add_property (t);
        }

        else 
        {
        }
      }
    }

    // ResourceDeploymentDescription
    //

    ResourceDeploymentDescription::
    ResourceDeploymentDescription (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "requirementName")
        {
          requirementName_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          requirementName_->container (this);
        }

        else if (n == "resourceName")
        {
          resourceName_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          resourceName_->container (this);
        }

        else if (n == "property")
        {
          ::CIAO::Config_Handlers::Property t (e);
          add_property (t);
        }

        else 
        {
        }
      }
    }

    // ArtifactDeploymentDescription
    //

    ArtifactDeploymentDescription::
    ArtifactDeploymentDescription (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "name")
        {
          name_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          name_->container (this);
        }

        else if (n == "source")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          add_source (t);
        }

        else if (n == "node")
        {
          node_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          node_->container (this);
        }

        else if (n == "location")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          add_location (t);
        }

        else if (n == "execParameter")
        {
          ::CIAO::Config_Handlers::Property t (e);
          add_execParameter (t);
        }

        else if (n == "deployRequirement")
        {
          ::CIAO::Config_Handlers::Requirement t (e);
          add_deployRequirement (t);
        }

        else if (n == "deployedResource")
        {
          ::CIAO::Config_Handlers::ResourceDeploymentDescription t (e);
          add_deployedResource (t);
        }

        else 
        {
        }
      }

      while (p.more_attributes ())
      {
        ::XSCRT::XML::Attribute< ACE_TCHAR > a (p.next_attribute ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (a.name ()));
        if (n == "id")
        {
          ::XMLSchema::ID< ACE_TCHAR > t (a);
          id (t);
        }

        else 
        {
        }
      }
    }

    // MonolithicDeploymentDescription
    //

    MonolithicDeploymentDescription::
    MonolithicDeploymentDescription (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "name")
        {
          name_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          name_->container (this);
        }

        else if (n == "source")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          add_source (t);
        }

        else if (n == "artifact")
        {
          ::XMLSchema::IDREF< ACE_TCHAR > t (e);
          add_artifact (t);
        }

        else if (n == "execParameter")
        {
          ::CIAO::Config_Handlers::Property t (e);
          add_execParameter (t);
        }

        else if (n == "deployRequirement")
        {
          ::CIAO::Config_Handlers::Requirement t (e);
          add_deployRequirement (t);
        }

        else 
        {
        }
      }

      while (p.more_attributes ())
      {
        ::XSCRT::XML::Attribute< ACE_TCHAR > a (p.next_attribute ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (a.name ()));
        if (n == "id")
        {
          ::XMLSchema::ID< ACE_TCHAR > t (a);
          id (t);
        }

        else 
        {
        }
      }
    }

    // ResourceUsageKind
    //

    ResourceUsageKind::
    ResourceUsageKind (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    : ::XSCRT::Type (e)
    {
      ::std::basic_string< ACE_TCHAR > v (e.value ());

      if (v == "None") v_ = None_l;
      else if (v == "InstanceUsesResource") v_ = InstanceUsesResource_l;
      else if (v == "ResourceUsesInstance") v_ = ResourceUsesInstance_l;
      else if (v == "PortUsesResource") v_ = PortUsesResource_l;
      else if (v == "ResourceUsesPort") v_ = ResourceUsesPort_l;
      else 
      {
      }
    }

    ResourceUsageKind::
    ResourceUsageKind (::XSCRT::XML::Attribute< ACE_TCHAR > const& a)
    : ::XSCRT::Type (a)
    {
      ::std::basic_string< ACE_TCHAR > v (a.value ());

      if (v == "None") v_ = None_l;
      else if (v == "InstanceUsesResource") v_ = InstanceUsesResource_l;
      else if (v == "ResourceUsesInstance") v_ = ResourceUsesInstance_l;
      else if (v == "PortUsesResource") v_ = PortUsesResource_l;
      else if (v == "ResourceUsesPort") v_ = ResourceUsesPort_l;
      else 
      {
      }
    }

    ResourceUsageKind const ResourceUsageKind::None (ResourceUsageKind::None_l);
    ResourceUsageKind const ResourceUsageKind::InstanceUsesResource (ResourceUsageKind::InstanceUsesResource_l);
    ResourceUsageKind const ResourceUsageKind::ResourceUsesInstance (ResourceUsageKind::ResourceUsesInstance_l);
    ResourceUsageKind const ResourceUsageKind::PortUsesResource (ResourceUsageKind::PortUsesResource_l);
    ResourceUsageKind const ResourceUsageKind::ResourceUsesPort (ResourceUsageKind::ResourceUsesPort_l);

    // InstanceResourceDeploymentDescription
    //

    InstanceResourceDeploymentDescription::
    InstanceResourceDeploymentDescription (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "resourceUsage")
        {
          resourceUsage_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ResourceUsageKind > (new ::CIAO::Config_Handlers::ResourceUsageKind (e));
          resourceUsage_->container (this);
        }

        else if (n == "requirementName")
        {
          requirementName_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          requirementName_->container (this);
        }

        else if (n == "resourceName")
        {
          resourceName_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          resourceName_->container (this);
        }

        else if (n == "property")
        {
          ::CIAO::Config_Handlers::Property t (e);
          add_property (t);
        }

        else 
        {
        }
      }
    }

    // InstanceDeploymentDescription
    //

    InstanceDeploymentDescription::
    InstanceDeploymentDescription (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "name")
        {
          name_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          name_->container (this);
        }

        else if (n == "node")
        {
          node_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          node_->container (this);
        }

        else if (n == "source")
        {
          source_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          source_->container (this);
        }

        else if (n == "implementation")
        {
          implementation_ = ::std::auto_ptr< ::XMLSchema::IDREF< ACE_TCHAR > > (new ::XMLSchema::IDREF< ACE_TCHAR > (e));
          implementation_->container (this);
        }

        else if (n == "configProperty")
        {
          ::CIAO::Config_Handlers::Property t (e);
          add_configProperty (t);
        }

        else if (n == "deployedResource")
        {
          ::CIAO::Config_Handlers::InstanceResourceDeploymentDescription t (e);
          add_deployedResource (t);
        }

        else if (n == "deployedSharedResource")
        {
          ::CIAO::Config_Handlers::InstanceResourceDeploymentDescription t (e);
          deployedSharedResource (t);
        }

        else 
        {
        }
      }

      while (p.more_attributes ())
      {
        ::XSCRT::XML::Attribute< ACE_TCHAR > a (p.next_attribute ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (a.name ()));
        if (n == "id")
        {
          ::XMLSchema::ID< ACE_TCHAR > t (a);
          id (t);
        }

        else 
        {
        }
      }
    }

    // CCMComponentPortKind
    //

    CCMComponentPortKind::
    CCMComponentPortKind (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    : ::XSCRT::Type (e)
    {
      ::std::basic_string< ACE_TCHAR > v (e.value ());

      if (v == "Facet") v_ = Facet_l;
      else if (v == "SimplexReceptacle") v_ = SimplexReceptacle_l;
      else if (v == "MultiplexReceptacle") v_ = MultiplexReceptacle_l;
      else if (v == "EventEmitter") v_ = EventEmitter_l;
      else if (v == "EventPublisher") v_ = EventPublisher_l;
      else if (v == "EventConsumer") v_ = EventConsumer_l;
      else 
      {
      }
    }

    CCMComponentPortKind::
    CCMComponentPortKind (::XSCRT::XML::Attribute< ACE_TCHAR > const& a)
    : ::XSCRT::Type (a)
    {
      ::std::basic_string< ACE_TCHAR > v (a.value ());

      if (v == "Facet") v_ = Facet_l;
      else if (v == "SimplexReceptacle") v_ = SimplexReceptacle_l;
      else if (v == "MultiplexReceptacle") v_ = MultiplexReceptacle_l;
      else if (v == "EventEmitter") v_ = EventEmitter_l;
      else if (v == "EventPublisher") v_ = EventPublisher_l;
      else if (v == "EventConsumer") v_ = EventConsumer_l;
      else 
      {
      }
    }

    CCMComponentPortKind const CCMComponentPortKind::Facet (CCMComponentPortKind::Facet_l);
    CCMComponentPortKind const CCMComponentPortKind::SimplexReceptacle (CCMComponentPortKind::SimplexReceptacle_l);
    CCMComponentPortKind const CCMComponentPortKind::MultiplexReceptacle (CCMComponentPortKind::MultiplexReceptacle_l);
    CCMComponentPortKind const CCMComponentPortKind::EventEmitter (CCMComponentPortKind::EventEmitter_l);
    CCMComponentPortKind const CCMComponentPortKind::EventPublisher (CCMComponentPortKind::EventPublisher_l);
    CCMComponentPortKind const CCMComponentPortKind::EventConsumer (CCMComponentPortKind::EventConsumer_l);

    // ComponentPortDescription
    //

    ComponentPortDescription::
    ComponentPortDescription (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "name")
        {
          name_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          name_->container (this);
        }

        else if (n == "specificType")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          specificType (t);
        }

        else if (n == "supportedType")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          add_supportedType (t);
        }

        else if (n == "provider")
        {
          provider_ = ::std::auto_ptr< ::XMLSchema::boolean > (new ::XMLSchema::boolean (e));
          provider_->container (this);
        }

        else if (n == "exclusiveProvider")
        {
          exclusiveProvider_ = ::std::auto_ptr< ::XMLSchema::boolean > (new ::XMLSchema::boolean (e));
          exclusiveProvider_->container (this);
        }

        else if (n == "exclusiveUser")
        {
          exclusiveUser_ = ::std::auto_ptr< ::XMLSchema::boolean > (new ::XMLSchema::boolean (e));
          exclusiveUser_->container (this);
        }

        else if (n == "optional")
        {
          optional_ = ::std::auto_ptr< ::XMLSchema::boolean > (new ::XMLSchema::boolean (e));
          optional_->container (this);
        }

        else if (n == "kind")
        {
          kind_ = ::std::auto_ptr< ::CIAO::Config_Handlers::CCMComponentPortKind > (new ::CIAO::Config_Handlers::CCMComponentPortKind (e));
          kind_->container (this);
        }

        else 
        {
        }
      }
    }

    // ComponentPropertyDescription
    //

    ComponentPropertyDescription::
    ComponentPropertyDescription (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "name")
        {
          name_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          name_->container (this);
        }

        else if (n == "type")
        {
          type_ = ::std::auto_ptr< ::CIAO::Config_Handlers::DataType > (new ::CIAO::Config_Handlers::DataType (e));
          type_->container (this);
        }

        else 
        {
        }
      }
    }

    // ComponentExternalPortEndpoint
    //

    ComponentExternalPortEndpoint::
    ComponentExternalPortEndpoint (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "portName")
        {
          portName_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          portName_->container (this);
        }

        else 
        {
        }
      }
    }

    // PlanSubcomponentPortEndpoint
    //

    PlanSubcomponentPortEndpoint::
    PlanSubcomponentPortEndpoint (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "portName")
        {
          portName_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          portName_->container (this);
        }

        else if (n == "provider")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          provider (t);
        }

        else if (n == "kind")
        {
          kind_ = ::std::auto_ptr< ::CIAO::Config_Handlers::CCMComponentPortKind > (new ::CIAO::Config_Handlers::CCMComponentPortKind (e));
          kind_->container (this);
        }

        else if (n == "instance")
        {
          instance_ = ::std::auto_ptr< ::XMLSchema::IDREF< ACE_TCHAR > > (new ::XMLSchema::IDREF< ACE_TCHAR > (e));
          instance_->container (this);
        }

        else 
        {
        }
      }
    }

    // ExternalReferenceEndpoint
    //

    ExternalReferenceEndpoint::
    ExternalReferenceEndpoint (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "location")
        {
          location_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          location_->container (this);
        }

        else 
        {
        }
      }
    }

    // ConnectionResourceDeploymentDescription
    //

    ConnectionResourceDeploymentDescription::
    ConnectionResourceDeploymentDescription (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "targetName")
        {
          targetName_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          targetName_->container (this);
        }

        else if (n == "requirementName")
        {
          requirementName_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          requirementName_->container (this);
        }

        else if (n == "resourceName")
        {
          resourceName_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          resourceName_->container (this);
        }

        else if (n == "property")
        {
          ::CIAO::Config_Handlers::Property t (e);
          add_property (t);
        }

        else 
        {
        }
      }
    }

    // PlanConnectionDescription
    //

    PlanConnectionDescription::
    PlanConnectionDescription (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "name")
        {
          name_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          name_->container (this);
        }

        else if (n == "source")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          source (t);
        }

        else if (n == "deployRequirement")
        {
          ::CIAO::Config_Handlers::Requirement t (e);
          add_deployRequirement (t);
        }

        else if (n == "externalEndpoint")
        {
          ::CIAO::Config_Handlers::ComponentExternalPortEndpoint t (e);
          add_externalEndpoint (t);
        }

        else if (n == "internalEndpoint")
        {
          ::CIAO::Config_Handlers::PlanSubcomponentPortEndpoint t (e);
          add_internalEndpoint (t);
        }

        else if (n == "externalReference")
        {
          ::CIAO::Config_Handlers::ExternalReferenceEndpoint t (e);
          add_externalReference (t);
        }

        else if (n == "deployedResource")
        {
          ::CIAO::Config_Handlers::ConnectionResourceDeploymentDescription t (e);
          add_deployedResource (t);
        }

        else 
        {
        }
      }
    }

    // ImplementationDependency
    //

    ImplementationDependency::
    ImplementationDependency (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "requiredType")
        {
          requiredType_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          requiredType_->container (this);
        }

        else 
        {
        }
      }
    }

    // Capability
    //

    Capability::
    Capability (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "name")
        {
          name_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          name_->container (this);
        }

        else if (n == "resourceType")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          add_resourceType (t);
        }

        else if (n == "property")
        {
          ::CIAO::Config_Handlers::SatisfierProperty t (e);
          add_property (t);
        }

        else 
        {
        }
      }
    }

    // ImplementationRequirement
    //

    ImplementationRequirement::
    ImplementationRequirement (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "resourceUsage")
        {
          ::CIAO::Config_Handlers::ResourceUsageKind t (e);
          resourceUsage (t);
        }

        else if (n == "resourcePort")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          resourcePort (t);
        }

        else if (n == "componentPort")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          componentPort (t);
        }

        else if (n == "resourceType")
        {
          resourceType_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          resourceType_->container (this);
        }

        else if (n == "name")
        {
          name_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          name_->container (this);
        }

        else if (n == "property")
        {
          ::CIAO::Config_Handlers::Property t (e);
          add_property (t);
        }

        else 
        {
        }
      }
    }

    // ComponentPackageReference
    //

    ComponentPackageReference::
    ComponentPackageReference (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "requiredUUID")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          requiredUUID (t);
        }

        else if (n == "requiredName")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          requiredName (t);
        }

        else if (n == "requiredType")
        {
          requiredType_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          requiredType_->container (this);
        }

        else 
        {
        }
      }
    }

    // SubcomponentPortEndpoint
    //

    SubcomponentPortEndpoint::
    SubcomponentPortEndpoint (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "portName")
        {
          portName_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          portName_->container (this);
        }

        else if (n == "instance")
        {
          instance_ = ::std::auto_ptr< ::XMLSchema::IDREF< ACE_TCHAR > > (new ::XMLSchema::IDREF< ACE_TCHAR > (e));
          instance_->container (this);
        }

        else 
        {
        }
      }
    }

    // AssemblyConnectionDescription
    //

    AssemblyConnectionDescription::
    AssemblyConnectionDescription (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "name")
        {
          name_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          name_->container (this);
        }

        else if (n == "deployRequirement")
        {
          ::CIAO::Config_Handlers::Requirement t (e);
          add_deployRequirement (t);
        }

        else if (n == "internalEndpoint")
        {
          ::CIAO::Config_Handlers::SubcomponentPortEndpoint t (e);
          add_internalEndpoint (t);
        }

        else if (n == "externalEndpoint")
        {
          ::CIAO::Config_Handlers::ComponentExternalPortEndpoint t (e);
          add_externalEndpoint (t);
        }

        else if (n == "externalReference")
        {
          ::CIAO::Config_Handlers::ExternalReferenceEndpoint t (e);
          add_externalReference (t);
        }

        else 
        {
        }
      }
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
  }
}

#include "XMLSchema/TypeInfo.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace
    {
      ::XMLSchema::TypeInfoInitializer < ACE_TCHAR > XMLSchemaTypeInfoInitializer_ (::XSCRT::extended_type_info_map ());

      struct TCKindTypeInfoInitializer
      {
        TCKindTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (TCKind));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));

          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      TCKindTypeInfoInitializer TCKindTypeInfoInitializer_;

      struct DataTypeTypeInfoInitializer
      {
        DataTypeTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (DataType));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      DataTypeTypeInfoInitializer DataTypeTypeInfoInitializer_;

      struct DataValueTypeInfoInitializer
      {
        DataValueTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (DataValue));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      DataValueTypeInfoInitializer DataValueTypeInfoInitializer_;

      struct EnumTypeTypeInfoInitializer
      {
        EnumTypeTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (EnumType));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      EnumTypeTypeInfoInitializer EnumTypeTypeInfoInitializer_;

      struct AnyTypeInfoInitializer
      {
        AnyTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (Any));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      AnyTypeInfoInitializer AnyTypeInfoInitializer_;

      struct PropertyTypeInfoInitializer
      {
        PropertyTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (Property));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      PropertyTypeInfoInitializer PropertyTypeInfoInitializer_;

      struct SatisfierPropertyKindTypeInfoInitializer
      {
        SatisfierPropertyKindTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (SatisfierPropertyKind));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));

          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      SatisfierPropertyKindTypeInfoInitializer SatisfierPropertyKindTypeInfoInitializer_;

      struct SatisfierPropertyTypeInfoInitializer
      {
        SatisfierPropertyTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (SatisfierProperty));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      SatisfierPropertyTypeInfoInitializer SatisfierPropertyTypeInfoInitializer_;

      struct ResourceTypeInfoInitializer
      {
        ResourceTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (Resource));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      ResourceTypeInfoInitializer ResourceTypeInfoInitializer_;

      struct RequirementTypeInfoInitializer
      {
        RequirementTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (Requirement));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      RequirementTypeInfoInitializer RequirementTypeInfoInitializer_;

      struct ResourceDeploymentDescriptionTypeInfoInitializer
      {
        ResourceDeploymentDescriptionTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (ResourceDeploymentDescription));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      ResourceDeploymentDescriptionTypeInfoInitializer ResourceDeploymentDescriptionTypeInfoInitializer_;

      struct ArtifactDeploymentDescriptionTypeInfoInitializer
      {
        ArtifactDeploymentDescriptionTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (ArtifactDeploymentDescription));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      ArtifactDeploymentDescriptionTypeInfoInitializer ArtifactDeploymentDescriptionTypeInfoInitializer_;

      struct MonolithicDeploymentDescriptionTypeInfoInitializer
      {
        MonolithicDeploymentDescriptionTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (MonolithicDeploymentDescription));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      MonolithicDeploymentDescriptionTypeInfoInitializer MonolithicDeploymentDescriptionTypeInfoInitializer_;

      struct ResourceUsageKindTypeInfoInitializer
      {
        ResourceUsageKindTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (ResourceUsageKind));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));

          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      ResourceUsageKindTypeInfoInitializer ResourceUsageKindTypeInfoInitializer_;

      struct InstanceResourceDeploymentDescriptionTypeInfoInitializer
      {
        InstanceResourceDeploymentDescriptionTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (InstanceResourceDeploymentDescription));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      InstanceResourceDeploymentDescriptionTypeInfoInitializer InstanceResourceDeploymentDescriptionTypeInfoInitializer_;

      struct InstanceDeploymentDescriptionTypeInfoInitializer
      {
        InstanceDeploymentDescriptionTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (InstanceDeploymentDescription));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      InstanceDeploymentDescriptionTypeInfoInitializer InstanceDeploymentDescriptionTypeInfoInitializer_;

      struct CCMComponentPortKindTypeInfoInitializer
      {
        CCMComponentPortKindTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (CCMComponentPortKind));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));

          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      CCMComponentPortKindTypeInfoInitializer CCMComponentPortKindTypeInfoInitializer_;

      struct ComponentPortDescriptionTypeInfoInitializer
      {
        ComponentPortDescriptionTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (ComponentPortDescription));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      ComponentPortDescriptionTypeInfoInitializer ComponentPortDescriptionTypeInfoInitializer_;

      struct ComponentPropertyDescriptionTypeInfoInitializer
      {
        ComponentPropertyDescriptionTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (ComponentPropertyDescription));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      ComponentPropertyDescriptionTypeInfoInitializer ComponentPropertyDescriptionTypeInfoInitializer_;

      struct ComponentExternalPortEndpointTypeInfoInitializer
      {
        ComponentExternalPortEndpointTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (ComponentExternalPortEndpoint));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      ComponentExternalPortEndpointTypeInfoInitializer ComponentExternalPortEndpointTypeInfoInitializer_;

      struct PlanSubcomponentPortEndpointTypeInfoInitializer
      {
        PlanSubcomponentPortEndpointTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (PlanSubcomponentPortEndpoint));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      PlanSubcomponentPortEndpointTypeInfoInitializer PlanSubcomponentPortEndpointTypeInfoInitializer_;

      struct ExternalReferenceEndpointTypeInfoInitializer
      {
        ExternalReferenceEndpointTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (ExternalReferenceEndpoint));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      ExternalReferenceEndpointTypeInfoInitializer ExternalReferenceEndpointTypeInfoInitializer_;

      struct ConnectionResourceDeploymentDescriptionTypeInfoInitializer
      {
        ConnectionResourceDeploymentDescriptionTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (ConnectionResourceDeploymentDescription));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      ConnectionResourceDeploymentDescriptionTypeInfoInitializer ConnectionResourceDeploymentDescriptionTypeInfoInitializer_;

      struct PlanConnectionDescriptionTypeInfoInitializer
      {
        PlanConnectionDescriptionTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (PlanConnectionDescription));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      PlanConnectionDescriptionTypeInfoInitializer PlanConnectionDescriptionTypeInfoInitializer_;

      struct ImplementationDependencyTypeInfoInitializer
      {
        ImplementationDependencyTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (ImplementationDependency));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      ImplementationDependencyTypeInfoInitializer ImplementationDependencyTypeInfoInitializer_;

      struct CapabilityTypeInfoInitializer
      {
        CapabilityTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (Capability));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      CapabilityTypeInfoInitializer CapabilityTypeInfoInitializer_;

      struct ImplementationRequirementTypeInfoInitializer
      {
        ImplementationRequirementTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (ImplementationRequirement));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      ImplementationRequirementTypeInfoInitializer ImplementationRequirementTypeInfoInitializer_;

      struct ComponentPackageReferenceTypeInfoInitializer
      {
        ComponentPackageReferenceTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (ComponentPackageReference));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      ComponentPackageReferenceTypeInfoInitializer ComponentPackageReferenceTypeInfoInitializer_;

      struct SubcomponentPortEndpointTypeInfoInitializer
      {
        SubcomponentPortEndpointTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (SubcomponentPortEndpoint));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      SubcomponentPortEndpointTypeInfoInitializer SubcomponentPortEndpointTypeInfoInitializer_;

      struct AssemblyConnectionDescriptionTypeInfoInitializer
      {
        AssemblyConnectionDescriptionTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (AssemblyConnectionDescription));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      AssemblyConnectionDescriptionTypeInfoInitializer AssemblyConnectionDescriptionTypeInfoInitializer_;
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Traversal
    {
      // DataType
      //
      //

      void DataType::
      traverse (Type& o)
      {
        pre (o);
        kind (o);
        if (o.enum_p ()) enum_ (o);
        else enum_none (o);
        post (o);
      }

      void DataType::
      traverse (Type const& o)
      {
        pre (o);
        kind (o);
        if (o.enum_p ()) enum_ (o);
        else enum_none (o);
        post (o);
      }

      void DataType::
      pre (Type&)
      {
      }

      void DataType::
      pre (Type const&)
      {
      }

      void DataType::
      kind (Type& o)
      {
        dispatch (o.kind ());
      }

      void DataType::
      kind (Type const& o)
      {
        dispatch (o.kind ());
      }

      void DataType::
      enum_ (Type& o)
      {
        dispatch (o.enum_ ());
      }

      void DataType::
      enum_ (Type const& o)
      {
        dispatch (o.enum_ ());
      }

      void DataType::
      enum_none (Type&)
      {
      }

      void DataType::
      enum_none (Type const&)
      {
      }

      void DataType::
      post (Type&)
      {
      }

      void DataType::
      post (Type const&)
      {
      }

      // DataValue
      //
      //

      void DataValue::
      traverse (Type& o)
      {
        pre (o);
        short_ (o);
        long_ (o);
        ushort (o);
        ulong (o);
        float_ (o);
        double_ (o);
        boolean (o);
        octet (o);
        enum_ (o);
        string (o);
        longlong (o);
        ulonglong (o);
        longdouble (o);
        post (o);
      }

      void DataValue::
      traverse (Type const& o)
      {
        pre (o);
        short_ (o);
        long_ (o);
        ushort (o);
        ulong (o);
        float_ (o);
        double_ (o);
        boolean (o);
        octet (o);
        enum_ (o);
        string (o);
        longlong (o);
        ulonglong (o);
        longdouble (o);
        post (o);
      }

      void DataValue::
      pre (Type&)
      {
      }

      void DataValue::
      pre (Type const&)
      {
      }

      void DataValue::
      short_ (Type& o)
      {
        // VC6 anathema strikes again
        //
        DataValue::Type::short_iterator b (o.begin_short()), e (o.end_short());

        if (b != e)
        {
          short_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) short_next (o);
          }

          short_post (o);
        }

        else short_none (o);
      }

      void DataValue::
      short_ (Type const& o)
      {
        // VC6 anathema strikes again
        //
        DataValue::Type::short_const_iterator b (o.begin_short()), e (o.end_short());

        if (b != e)
        {
          short_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) short_next (o);
          }

          short_post (o);
        }

        else short_none (o);
      }

      void DataValue::
      short_pre (Type&)
      {
      }

      void DataValue::
      short_pre (Type const&)
      {
      }

      void DataValue::
      short_next (Type&)
      {
      }

      void DataValue::
      short_next (Type const&)
      {
      }

      void DataValue::
      short_post (Type&)
      {
      }

      void DataValue::
      short_post (Type const&)
      {
      }

      void DataValue::
      short_none (Type&)
      {
      }

      void DataValue::
      short_none (Type const&)
      {
      }

      void DataValue::
      long_ (Type& o)
      {
        // VC6 anathema strikes again
        //
        DataValue::Type::long_iterator b (o.begin_long()), e (o.end_long());

        if (b != e)
        {
          long_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) long_next (o);
          }

          long_post (o);
        }

        else long_none (o);
      }

      void DataValue::
      long_ (Type const& o)
      {
        // VC6 anathema strikes again
        //
        DataValue::Type::long_const_iterator b (o.begin_long()), e (o.end_long());

        if (b != e)
        {
          long_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) long_next (o);
          }

          long_post (o);
        }

        else long_none (o);
      }

      void DataValue::
      long_pre (Type&)
      {
      }

      void DataValue::
      long_pre (Type const&)
      {
      }

      void DataValue::
      long_next (Type&)
      {
      }

      void DataValue::
      long_next (Type const&)
      {
      }

      void DataValue::
      long_post (Type&)
      {
      }

      void DataValue::
      long_post (Type const&)
      {
      }

      void DataValue::
      long_none (Type&)
      {
      }

      void DataValue::
      long_none (Type const&)
      {
      }

      void DataValue::
      ushort (Type& o)
      {
        // VC6 anathema strikes again
        //
        DataValue::Type::ushort_iterator b (o.begin_ushort()), e (o.end_ushort());

        if (b != e)
        {
          ushort_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) ushort_next (o);
          }

          ushort_post (o);
        }

        else ushort_none (o);
      }

      void DataValue::
      ushort (Type const& o)
      {
        // VC6 anathema strikes again
        //
        DataValue::Type::ushort_const_iterator b (o.begin_ushort()), e (o.end_ushort());

        if (b != e)
        {
          ushort_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) ushort_next (o);
          }

          ushort_post (o);
        }

        else ushort_none (o);
      }

      void DataValue::
      ushort_pre (Type&)
      {
      }

      void DataValue::
      ushort_pre (Type const&)
      {
      }

      void DataValue::
      ushort_next (Type&)
      {
      }

      void DataValue::
      ushort_next (Type const&)
      {
      }

      void DataValue::
      ushort_post (Type&)
      {
      }

      void DataValue::
      ushort_post (Type const&)
      {
      }

      void DataValue::
      ushort_none (Type&)
      {
      }

      void DataValue::
      ushort_none (Type const&)
      {
      }

      void DataValue::
      ulong (Type& o)
      {
        // VC6 anathema strikes again
        //
        DataValue::Type::ulong_iterator b (o.begin_ulong()), e (o.end_ulong());

        if (b != e)
        {
          ulong_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) ulong_next (o);
          }

          ulong_post (o);
        }

        else ulong_none (o);
      }

      void DataValue::
      ulong (Type const& o)
      {
        // VC6 anathema strikes again
        //
        DataValue::Type::ulong_const_iterator b (o.begin_ulong()), e (o.end_ulong());

        if (b != e)
        {
          ulong_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) ulong_next (o);
          }

          ulong_post (o);
        }

        else ulong_none (o);
      }

      void DataValue::
      ulong_pre (Type&)
      {
      }

      void DataValue::
      ulong_pre (Type const&)
      {
      }

      void DataValue::
      ulong_next (Type&)
      {
      }

      void DataValue::
      ulong_next (Type const&)
      {
      }

      void DataValue::
      ulong_post (Type&)
      {
      }

      void DataValue::
      ulong_post (Type const&)
      {
      }

      void DataValue::
      ulong_none (Type&)
      {
      }

      void DataValue::
      ulong_none (Type const&)
      {
      }

      void DataValue::
      float_ (Type& o)
      {
        // VC6 anathema strikes again
        //
        DataValue::Type::float_iterator b (o.begin_float()), e (o.end_float());

        if (b != e)
        {
          float_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) float_next (o);
          }

          float_post (o);
        }

        else float_none (o);
      }

      void DataValue::
      float_ (Type const& o)
      {
        // VC6 anathema strikes again
        //
        DataValue::Type::float_const_iterator b (o.begin_float()), e (o.end_float());

        if (b != e)
        {
          float_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) float_next (o);
          }

          float_post (o);
        }

        else float_none (o);
      }

      void DataValue::
      float_pre (Type&)
      {
      }

      void DataValue::
      float_pre (Type const&)
      {
      }

      void DataValue::
      float_next (Type&)
      {
      }

      void DataValue::
      float_next (Type const&)
      {
      }

      void DataValue::
      float_post (Type&)
      {
      }

      void DataValue::
      float_post (Type const&)
      {
      }

      void DataValue::
      float_none (Type&)
      {
      }

      void DataValue::
      float_none (Type const&)
      {
      }

      void DataValue::
      double_ (Type& o)
      {
        // VC6 anathema strikes again
        //
        DataValue::Type::double_iterator b (o.begin_double()), e (o.end_double());

        if (b != e)
        {
          double_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) double_next (o);
          }

          double_post (o);
        }

        else double_none (o);
      }

      void DataValue::
      double_ (Type const& o)
      {
        // VC6 anathema strikes again
        //
        DataValue::Type::double_const_iterator b (o.begin_double()), e (o.end_double());

        if (b != e)
        {
          double_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) double_next (o);
          }

          double_post (o);
        }

        else double_none (o);
      }

      void DataValue::
      double_pre (Type&)
      {
      }

      void DataValue::
      double_pre (Type const&)
      {
      }

      void DataValue::
      double_next (Type&)
      {
      }

      void DataValue::
      double_next (Type const&)
      {
      }

      void DataValue::
      double_post (Type&)
      {
      }

      void DataValue::
      double_post (Type const&)
      {
      }

      void DataValue::
      double_none (Type&)
      {
      }

      void DataValue::
      double_none (Type const&)
      {
      }

      void DataValue::
      boolean (Type& o)
      {
        // VC6 anathema strikes again
        //
        DataValue::Type::boolean_iterator b (o.begin_boolean()), e (o.end_boolean());

        if (b != e)
        {
          boolean_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) boolean_next (o);
          }

          boolean_post (o);
        }

        else boolean_none (o);
      }

      void DataValue::
      boolean (Type const& o)
      {
        // VC6 anathema strikes again
        //
        DataValue::Type::boolean_const_iterator b (o.begin_boolean()), e (o.end_boolean());

        if (b != e)
        {
          boolean_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) boolean_next (o);
          }

          boolean_post (o);
        }

        else boolean_none (o);
      }

      void DataValue::
      boolean_pre (Type&)
      {
      }

      void DataValue::
      boolean_pre (Type const&)
      {
      }

      void DataValue::
      boolean_next (Type&)
      {
      }

      void DataValue::
      boolean_next (Type const&)
      {
      }

      void DataValue::
      boolean_post (Type&)
      {
      }

      void DataValue::
      boolean_post (Type const&)
      {
      }

      void DataValue::
      boolean_none (Type&)
      {
      }

      void DataValue::
      boolean_none (Type const&)
      {
      }

      void DataValue::
      octet (Type& o)
      {
        // VC6 anathema strikes again
        //
        DataValue::Type::octet_iterator b (o.begin_octet()), e (o.end_octet());

        if (b != e)
        {
          octet_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) octet_next (o);
          }

          octet_post (o);
        }

        else octet_none (o);
      }

      void DataValue::
      octet (Type const& o)
      {
        // VC6 anathema strikes again
        //
        DataValue::Type::octet_const_iterator b (o.begin_octet()), e (o.end_octet());

        if (b != e)
        {
          octet_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) octet_next (o);
          }

          octet_post (o);
        }

        else octet_none (o);
      }

      void DataValue::
      octet_pre (Type&)
      {
      }

      void DataValue::
      octet_pre (Type const&)
      {
      }

      void DataValue::
      octet_next (Type&)
      {
      }

      void DataValue::
      octet_next (Type const&)
      {
      }

      void DataValue::
      octet_post (Type&)
      {
      }

      void DataValue::
      octet_post (Type const&)
      {
      }

      void DataValue::
      octet_none (Type&)
      {
      }

      void DataValue::
      octet_none (Type const&)
      {
      }

      void DataValue::
      enum_ (Type& o)
      {
        // VC6 anathema strikes again
        //
        DataValue::Type::enum_iterator b (o.begin_enum()), e (o.end_enum());

        if (b != e)
        {
          enum_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) enum_next (o);
          }

          enum_post (o);
        }

        else enum_none (o);
      }

      void DataValue::
      enum_ (Type const& o)
      {
        // VC6 anathema strikes again
        //
        DataValue::Type::enum_const_iterator b (o.begin_enum()), e (o.end_enum());

        if (b != e)
        {
          enum_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) enum_next (o);
          }

          enum_post (o);
        }

        else enum_none (o);
      }

      void DataValue::
      enum_pre (Type&)
      {
      }

      void DataValue::
      enum_pre (Type const&)
      {
      }

      void DataValue::
      enum_next (Type&)
      {
      }

      void DataValue::
      enum_next (Type const&)
      {
      }

      void DataValue::
      enum_post (Type&)
      {
      }

      void DataValue::
      enum_post (Type const&)
      {
      }

      void DataValue::
      enum_none (Type&)
      {
      }

      void DataValue::
      enum_none (Type const&)
      {
      }

      void DataValue::
      string (Type& o)
      {
        // VC6 anathema strikes again
        //
        DataValue::Type::string_iterator b (o.begin_string()), e (o.end_string());

        if (b != e)
        {
          string_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) string_next (o);
          }

          string_post (o);
        }

        else string_none (o);
      }

      void DataValue::
      string (Type const& o)
      {
        // VC6 anathema strikes again
        //
        DataValue::Type::string_const_iterator b (o.begin_string()), e (o.end_string());

        if (b != e)
        {
          string_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) string_next (o);
          }

          string_post (o);
        }

        else string_none (o);
      }

      void DataValue::
      string_pre (Type&)
      {
      }

      void DataValue::
      string_pre (Type const&)
      {
      }

      void DataValue::
      string_next (Type&)
      {
      }

      void DataValue::
      string_next (Type const&)
      {
      }

      void DataValue::
      string_post (Type&)
      {
      }

      void DataValue::
      string_post (Type const&)
      {
      }

      void DataValue::
      string_none (Type&)
      {
      }

      void DataValue::
      string_none (Type const&)
      {
      }

      void DataValue::
      longlong (Type& o)
      {
        // VC6 anathema strikes again
        //
        DataValue::Type::longlong_iterator b (o.begin_longlong()), e (o.end_longlong());

        if (b != e)
        {
          longlong_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) longlong_next (o);
          }

          longlong_post (o);
        }

        else longlong_none (o);
      }

      void DataValue::
      longlong (Type const& o)
      {
        // VC6 anathema strikes again
        //
        DataValue::Type::longlong_const_iterator b (o.begin_longlong()), e (o.end_longlong());

        if (b != e)
        {
          longlong_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) longlong_next (o);
          }

          longlong_post (o);
        }

        else longlong_none (o);
      }

      void DataValue::
      longlong_pre (Type&)
      {
      }

      void DataValue::
      longlong_pre (Type const&)
      {
      }

      void DataValue::
      longlong_next (Type&)
      {
      }

      void DataValue::
      longlong_next (Type const&)
      {
      }

      void DataValue::
      longlong_post (Type&)
      {
      }

      void DataValue::
      longlong_post (Type const&)
      {
      }

      void DataValue::
      longlong_none (Type&)
      {
      }

      void DataValue::
      longlong_none (Type const&)
      {
      }

      void DataValue::
      ulonglong (Type& o)
      {
        // VC6 anathema strikes again
        //
        DataValue::Type::ulonglong_iterator b (o.begin_ulonglong()), e (o.end_ulonglong());

        if (b != e)
        {
          ulonglong_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) ulonglong_next (o);
          }

          ulonglong_post (o);
        }

        else ulonglong_none (o);
      }

      void DataValue::
      ulonglong (Type const& o)
      {
        // VC6 anathema strikes again
        //
        DataValue::Type::ulonglong_const_iterator b (o.begin_ulonglong()), e (o.end_ulonglong());

        if (b != e)
        {
          ulonglong_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) ulonglong_next (o);
          }

          ulonglong_post (o);
        }

        else ulonglong_none (o);
      }

      void DataValue::
      ulonglong_pre (Type&)
      {
      }

      void DataValue::
      ulonglong_pre (Type const&)
      {
      }

      void DataValue::
      ulonglong_next (Type&)
      {
      }

      void DataValue::
      ulonglong_next (Type const&)
      {
      }

      void DataValue::
      ulonglong_post (Type&)
      {
      }

      void DataValue::
      ulonglong_post (Type const&)
      {
      }

      void DataValue::
      ulonglong_none (Type&)
      {
      }

      void DataValue::
      ulonglong_none (Type const&)
      {
      }

      void DataValue::
      longdouble (Type& o)
      {
        // VC6 anathema strikes again
        //
        DataValue::Type::longdouble_iterator b (o.begin_longdouble()), e (o.end_longdouble());

        if (b != e)
        {
          longdouble_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) longdouble_next (o);
          }

          longdouble_post (o);
        }

        else longdouble_none (o);
      }

      void DataValue::
      longdouble (Type const& o)
      {
        // VC6 anathema strikes again
        //
        DataValue::Type::longdouble_const_iterator b (o.begin_longdouble()), e (o.end_longdouble());

        if (b != e)
        {
          longdouble_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) longdouble_next (o);
          }

          longdouble_post (o);
        }

        else longdouble_none (o);
      }

      void DataValue::
      longdouble_pre (Type&)
      {
      }

      void DataValue::
      longdouble_pre (Type const&)
      {
      }

      void DataValue::
      longdouble_next (Type&)
      {
      }

      void DataValue::
      longdouble_next (Type const&)
      {
      }

      void DataValue::
      longdouble_post (Type&)
      {
      }

      void DataValue::
      longdouble_post (Type const&)
      {
      }

      void DataValue::
      longdouble_none (Type&)
      {
      }

      void DataValue::
      longdouble_none (Type const&)
      {
      }

      void DataValue::
      post (Type&)
      {
      }

      void DataValue::
      post (Type const&)
      {
      }

      // EnumType
      //
      //

      void EnumType::
      traverse (Type& o)
      {
        pre (o);
        name (o);
        typeId (o);
        member (o);
        post (o);
      }

      void EnumType::
      traverse (Type const& o)
      {
        pre (o);
        name (o);
        typeId (o);
        member (o);
        post (o);
      }

      void EnumType::
      pre (Type&)
      {
      }

      void EnumType::
      pre (Type const&)
      {
      }

      void EnumType::
      name (Type& o)
      {
        dispatch (o.name ());
      }

      void EnumType::
      name (Type const& o)
      {
        dispatch (o.name ());
      }

      void EnumType::
      typeId (Type& o)
      {
        dispatch (o.typeId ());
      }

      void EnumType::
      typeId (Type const& o)
      {
        dispatch (o.typeId ());
      }

      void EnumType::
      member (Type& o)
      {
        // VC6 anathema strikes again
        //
        EnumType::Type::member_iterator b (o.begin_member()), e (o.end_member());

        if (b != e)
        {
          member_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) member_next (o);
          }

          member_post (o);
        }
      }

      void EnumType::
      member (Type const& o)
      {
        // VC6 anathema strikes again
        //
        EnumType::Type::member_const_iterator b (o.begin_member()), e (o.end_member());

        if (b != e)
        {
          member_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) member_next (o);
          }

          member_post (o);
        }
      }

      void EnumType::
      member_pre (Type&)
      {
      }

      void EnumType::
      member_pre (Type const&)
      {
      }

      void EnumType::
      member_next (Type&)
      {
      }

      void EnumType::
      member_next (Type const&)
      {
      }

      void EnumType::
      member_post (Type&)
      {
      }

      void EnumType::
      member_post (Type const&)
      {
      }

      void EnumType::
      post (Type&)
      {
      }

      void EnumType::
      post (Type const&)
      {
      }

      // Any
      //
      //

      void Any::
      traverse (Type& o)
      {
        pre (o);
        type (o);
        value (o);
        post (o);
      }

      void Any::
      traverse (Type const& o)
      {
        pre (o);
        type (o);
        value (o);
        post (o);
      }

      void Any::
      pre (Type&)
      {
      }

      void Any::
      pre (Type const&)
      {
      }

      void Any::
      type (Type& o)
      {
        dispatch (o.type ());
      }

      void Any::
      type (Type const& o)
      {
        dispatch (o.type ());
      }

      void Any::
      value (Type& o)
      {
        dispatch (o.value ());
      }

      void Any::
      value (Type const& o)
      {
        dispatch (o.value ());
      }

      void Any::
      post (Type&)
      {
      }

      void Any::
      post (Type const&)
      {
      }

      // Property
      //
      //

      void Property::
      traverse (Type& o)
      {
        pre (o);
        name (o);
        value (o);
        post (o);
      }

      void Property::
      traverse (Type const& o)
      {
        pre (o);
        name (o);
        value (o);
        post (o);
      }

      void Property::
      pre (Type&)
      {
      }

      void Property::
      pre (Type const&)
      {
      }

      void Property::
      name (Type& o)
      {
        dispatch (o.name ());
      }

      void Property::
      name (Type const& o)
      {
        dispatch (o.name ());
      }

      void Property::
      value (Type& o)
      {
        dispatch (o.value ());
      }

      void Property::
      value (Type const& o)
      {
        dispatch (o.value ());
      }

      void Property::
      post (Type&)
      {
      }

      void Property::
      post (Type const&)
      {
      }

      // SatisfierProperty
      //
      //

      void SatisfierProperty::
      traverse (Type& o)
      {
        pre (o);
        name (o);
        kind (o);
        dynamic (o);
        value (o);
        post (o);
      }

      void SatisfierProperty::
      traverse (Type const& o)
      {
        pre (o);
        name (o);
        kind (o);
        dynamic (o);
        value (o);
        post (o);
      }

      void SatisfierProperty::
      pre (Type&)
      {
      }

      void SatisfierProperty::
      pre (Type const&)
      {
      }

      void SatisfierProperty::
      name (Type& o)
      {
        dispatch (o.name ());
      }

      void SatisfierProperty::
      name (Type const& o)
      {
        dispatch (o.name ());
      }

      void SatisfierProperty::
      kind (Type& o)
      {
        dispatch (o.kind ());
      }

      void SatisfierProperty::
      kind (Type const& o)
      {
        dispatch (o.kind ());
      }

      void SatisfierProperty::
      dynamic (Type& o)
      {
        dispatch (o.dynamic ());
      }

      void SatisfierProperty::
      dynamic (Type const& o)
      {
        dispatch (o.dynamic ());
      }

      void SatisfierProperty::
      value (Type& o)
      {
        dispatch (o.value ());
      }

      void SatisfierProperty::
      value (Type const& o)
      {
        dispatch (o.value ());
      }

      void SatisfierProperty::
      post (Type&)
      {
      }

      void SatisfierProperty::
      post (Type const&)
      {
      }

      // Resource
      //
      //

      void Resource::
      traverse (Type& o)
      {
        pre (o);
        name (o);
        resourceType (o);
        property (o);
        post (o);
      }

      void Resource::
      traverse (Type const& o)
      {
        pre (o);
        name (o);
        resourceType (o);
        property (o);
        post (o);
      }

      void Resource::
      pre (Type&)
      {
      }

      void Resource::
      pre (Type const&)
      {
      }

      void Resource::
      name (Type& o)
      {
        dispatch (o.name ());
      }

      void Resource::
      name (Type const& o)
      {
        dispatch (o.name ());
      }

      void Resource::
      resourceType (Type& o)
      {
        // VC6 anathema strikes again
        //
        Resource::Type::resourceType_iterator b (o.begin_resourceType()), e (o.end_resourceType());

        if (b != e)
        {
          resourceType_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) resourceType_next (o);
          }

          resourceType_post (o);
        }
      }

      void Resource::
      resourceType (Type const& o)
      {
        // VC6 anathema strikes again
        //
        Resource::Type::resourceType_const_iterator b (o.begin_resourceType()), e (o.end_resourceType());

        if (b != e)
        {
          resourceType_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) resourceType_next (o);
          }

          resourceType_post (o);
        }
      }

      void Resource::
      resourceType_pre (Type&)
      {
      }

      void Resource::
      resourceType_pre (Type const&)
      {
      }

      void Resource::
      resourceType_next (Type&)
      {
      }

      void Resource::
      resourceType_next (Type const&)
      {
      }

      void Resource::
      resourceType_post (Type&)
      {
      }

      void Resource::
      resourceType_post (Type const&)
      {
      }

      void Resource::
      property (Type& o)
      {
        // VC6 anathema strikes again
        //
        Resource::Type::property_iterator b (o.begin_property()), e (o.end_property());

        if (b != e)
        {
          property_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) property_next (o);
          }

          property_post (o);
        }

        else property_none (o);
      }

      void Resource::
      property (Type const& o)
      {
        // VC6 anathema strikes again
        //
        Resource::Type::property_const_iterator b (o.begin_property()), e (o.end_property());

        if (b != e)
        {
          property_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) property_next (o);
          }

          property_post (o);
        }

        else property_none (o);
      }

      void Resource::
      property_pre (Type&)
      {
      }

      void Resource::
      property_pre (Type const&)
      {
      }

      void Resource::
      property_next (Type&)
      {
      }

      void Resource::
      property_next (Type const&)
      {
      }

      void Resource::
      property_post (Type&)
      {
      }

      void Resource::
      property_post (Type const&)
      {
      }

      void Resource::
      property_none (Type&)
      {
      }

      void Resource::
      property_none (Type const&)
      {
      }

      void Resource::
      post (Type&)
      {
      }

      void Resource::
      post (Type const&)
      {
      }

      // Requirement
      //
      //

      void Requirement::
      traverse (Type& o)
      {
        pre (o);
        resourceType (o);
        name (o);
        property (o);
        post (o);
      }

      void Requirement::
      traverse (Type const& o)
      {
        pre (o);
        resourceType (o);
        name (o);
        property (o);
        post (o);
      }

      void Requirement::
      pre (Type&)
      {
      }

      void Requirement::
      pre (Type const&)
      {
      }

      void Requirement::
      resourceType (Type& o)
      {
        dispatch (o.resourceType ());
      }

      void Requirement::
      resourceType (Type const& o)
      {
        dispatch (o.resourceType ());
      }

      void Requirement::
      name (Type& o)
      {
        dispatch (o.name ());
      }

      void Requirement::
      name (Type const& o)
      {
        dispatch (o.name ());
      }

      void Requirement::
      property (Type& o)
      {
        // VC6 anathema strikes again
        //
        Requirement::Type::property_iterator b (o.begin_property()), e (o.end_property());

        if (b != e)
        {
          property_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) property_next (o);
          }

          property_post (o);
        }

        else property_none (o);
      }

      void Requirement::
      property (Type const& o)
      {
        // VC6 anathema strikes again
        //
        Requirement::Type::property_const_iterator b (o.begin_property()), e (o.end_property());

        if (b != e)
        {
          property_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) property_next (o);
          }

          property_post (o);
        }

        else property_none (o);
      }

      void Requirement::
      property_pre (Type&)
      {
      }

      void Requirement::
      property_pre (Type const&)
      {
      }

      void Requirement::
      property_next (Type&)
      {
      }

      void Requirement::
      property_next (Type const&)
      {
      }

      void Requirement::
      property_post (Type&)
      {
      }

      void Requirement::
      property_post (Type const&)
      {
      }

      void Requirement::
      property_none (Type&)
      {
      }

      void Requirement::
      property_none (Type const&)
      {
      }

      void Requirement::
      post (Type&)
      {
      }

      void Requirement::
      post (Type const&)
      {
      }

      // ResourceDeploymentDescription
      //
      //

      void ResourceDeploymentDescription::
      traverse (Type& o)
      {
        pre (o);
        requirementName (o);
        resourceName (o);
        property (o);
        post (o);
      }

      void ResourceDeploymentDescription::
      traverse (Type const& o)
      {
        pre (o);
        requirementName (o);
        resourceName (o);
        property (o);
        post (o);
      }

      void ResourceDeploymentDescription::
      pre (Type&)
      {
      }

      void ResourceDeploymentDescription::
      pre (Type const&)
      {
      }

      void ResourceDeploymentDescription::
      requirementName (Type& o)
      {
        dispatch (o.requirementName ());
      }

      void ResourceDeploymentDescription::
      requirementName (Type const& o)
      {
        dispatch (o.requirementName ());
      }

      void ResourceDeploymentDescription::
      resourceName (Type& o)
      {
        dispatch (o.resourceName ());
      }

      void ResourceDeploymentDescription::
      resourceName (Type const& o)
      {
        dispatch (o.resourceName ());
      }

      void ResourceDeploymentDescription::
      property (Type& o)
      {
        // VC6 anathema strikes again
        //
        ResourceDeploymentDescription::Type::property_iterator b (o.begin_property()), e (o.end_property());

        if (b != e)
        {
          property_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) property_next (o);
          }

          property_post (o);
        }

        else property_none (o);
      }

      void ResourceDeploymentDescription::
      property (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ResourceDeploymentDescription::Type::property_const_iterator b (o.begin_property()), e (o.end_property());

        if (b != e)
        {
          property_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) property_next (o);
          }

          property_post (o);
        }

        else property_none (o);
      }

      void ResourceDeploymentDescription::
      property_pre (Type&)
      {
      }

      void ResourceDeploymentDescription::
      property_pre (Type const&)
      {
      }

      void ResourceDeploymentDescription::
      property_next (Type&)
      {
      }

      void ResourceDeploymentDescription::
      property_next (Type const&)
      {
      }

      void ResourceDeploymentDescription::
      property_post (Type&)
      {
      }

      void ResourceDeploymentDescription::
      property_post (Type const&)
      {
      }

      void ResourceDeploymentDescription::
      property_none (Type&)
      {
      }

      void ResourceDeploymentDescription::
      property_none (Type const&)
      {
      }

      void ResourceDeploymentDescription::
      post (Type&)
      {
      }

      void ResourceDeploymentDescription::
      post (Type const&)
      {
      }

      // ArtifactDeploymentDescription
      //
      //

      void ArtifactDeploymentDescription::
      traverse (Type& o)
      {
        pre (o);
        name (o);
        source (o);
        node (o);
        location (o);
        execParameter (o);
        deployRequirement (o);
        deployedResource (o);
        if (o.id_p ()) id (o);
        else id_none (o);
        post (o);
      }

      void ArtifactDeploymentDescription::
      traverse (Type const& o)
      {
        pre (o);
        name (o);
        source (o);
        node (o);
        location (o);
        execParameter (o);
        deployRequirement (o);
        deployedResource (o);
        if (o.id_p ()) id (o);
        else id_none (o);
        post (o);
      }

      void ArtifactDeploymentDescription::
      pre (Type&)
      {
      }

      void ArtifactDeploymentDescription::
      pre (Type const&)
      {
      }

      void ArtifactDeploymentDescription::
      name (Type& o)
      {
        dispatch (o.name ());
      }

      void ArtifactDeploymentDescription::
      name (Type const& o)
      {
        dispatch (o.name ());
      }

      void ArtifactDeploymentDescription::
      source (Type& o)
      {
        // VC6 anathema strikes again
        //
        ArtifactDeploymentDescription::Type::source_iterator b (o.begin_source()), e (o.end_source());

        if (b != e)
        {
          source_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) source_next (o);
          }

          source_post (o);
        }
      }

      void ArtifactDeploymentDescription::
      source (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ArtifactDeploymentDescription::Type::source_const_iterator b (o.begin_source()), e (o.end_source());

        if (b != e)
        {
          source_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) source_next (o);
          }

          source_post (o);
        }
      }

      void ArtifactDeploymentDescription::
      source_pre (Type&)
      {
      }

      void ArtifactDeploymentDescription::
      source_pre (Type const&)
      {
      }

      void ArtifactDeploymentDescription::
      source_next (Type&)
      {
      }

      void ArtifactDeploymentDescription::
      source_next (Type const&)
      {
      }

      void ArtifactDeploymentDescription::
      source_post (Type&)
      {
      }

      void ArtifactDeploymentDescription::
      source_post (Type const&)
      {
      }

      void ArtifactDeploymentDescription::
      node (Type& o)
      {
        dispatch (o.node ());
      }

      void ArtifactDeploymentDescription::
      node (Type const& o)
      {
        dispatch (o.node ());
      }

      void ArtifactDeploymentDescription::
      location (Type& o)
      {
        // VC6 anathema strikes again
        //
        ArtifactDeploymentDescription::Type::location_iterator b (o.begin_location()), e (o.end_location());

        if (b != e)
        {
          location_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) location_next (o);
          }

          location_post (o);
        }
      }

      void ArtifactDeploymentDescription::
      location (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ArtifactDeploymentDescription::Type::location_const_iterator b (o.begin_location()), e (o.end_location());

        if (b != e)
        {
          location_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) location_next (o);
          }

          location_post (o);
        }
      }

      void ArtifactDeploymentDescription::
      location_pre (Type&)
      {
      }

      void ArtifactDeploymentDescription::
      location_pre (Type const&)
      {
      }

      void ArtifactDeploymentDescription::
      location_next (Type&)
      {
      }

      void ArtifactDeploymentDescription::
      location_next (Type const&)
      {
      }

      void ArtifactDeploymentDescription::
      location_post (Type&)
      {
      }

      void ArtifactDeploymentDescription::
      location_post (Type const&)
      {
      }

      void ArtifactDeploymentDescription::
      execParameter (Type& o)
      {
        // VC6 anathema strikes again
        //
        ArtifactDeploymentDescription::Type::execParameter_iterator b (o.begin_execParameter()), e (o.end_execParameter());

        if (b != e)
        {
          execParameter_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) execParameter_next (o);
          }

          execParameter_post (o);
        }

        else execParameter_none (o);
      }

      void ArtifactDeploymentDescription::
      execParameter (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ArtifactDeploymentDescription::Type::execParameter_const_iterator b (o.begin_execParameter()), e (o.end_execParameter());

        if (b != e)
        {
          execParameter_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) execParameter_next (o);
          }

          execParameter_post (o);
        }

        else execParameter_none (o);
      }

      void ArtifactDeploymentDescription::
      execParameter_pre (Type&)
      {
      }

      void ArtifactDeploymentDescription::
      execParameter_pre (Type const&)
      {
      }

      void ArtifactDeploymentDescription::
      execParameter_next (Type&)
      {
      }

      void ArtifactDeploymentDescription::
      execParameter_next (Type const&)
      {
      }

      void ArtifactDeploymentDescription::
      execParameter_post (Type&)
      {
      }

      void ArtifactDeploymentDescription::
      execParameter_post (Type const&)
      {
      }

      void ArtifactDeploymentDescription::
      execParameter_none (Type&)
      {
      }

      void ArtifactDeploymentDescription::
      execParameter_none (Type const&)
      {
      }

      void ArtifactDeploymentDescription::
      deployRequirement (Type& o)
      {
        // VC6 anathema strikes again
        //
        ArtifactDeploymentDescription::Type::deployRequirement_iterator b (o.begin_deployRequirement()), e (o.end_deployRequirement());

        if (b != e)
        {
          deployRequirement_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) deployRequirement_next (o);
          }

          deployRequirement_post (o);
        }

        else deployRequirement_none (o);
      }

      void ArtifactDeploymentDescription::
      deployRequirement (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ArtifactDeploymentDescription::Type::deployRequirement_const_iterator b (o.begin_deployRequirement()), e (o.end_deployRequirement());

        if (b != e)
        {
          deployRequirement_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) deployRequirement_next (o);
          }

          deployRequirement_post (o);
        }

        else deployRequirement_none (o);
      }

      void ArtifactDeploymentDescription::
      deployRequirement_pre (Type&)
      {
      }

      void ArtifactDeploymentDescription::
      deployRequirement_pre (Type const&)
      {
      }

      void ArtifactDeploymentDescription::
      deployRequirement_next (Type&)
      {
      }

      void ArtifactDeploymentDescription::
      deployRequirement_next (Type const&)
      {
      }

      void ArtifactDeploymentDescription::
      deployRequirement_post (Type&)
      {
      }

      void ArtifactDeploymentDescription::
      deployRequirement_post (Type const&)
      {
      }

      void ArtifactDeploymentDescription::
      deployRequirement_none (Type&)
      {
      }

      void ArtifactDeploymentDescription::
      deployRequirement_none (Type const&)
      {
      }

      void ArtifactDeploymentDescription::
      deployedResource (Type& o)
      {
        // VC6 anathema strikes again
        //
        ArtifactDeploymentDescription::Type::deployedResource_iterator b (o.begin_deployedResource()), e (o.end_deployedResource());

        if (b != e)
        {
          deployedResource_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) deployedResource_next (o);
          }

          deployedResource_post (o);
        }

        else deployedResource_none (o);
      }

      void ArtifactDeploymentDescription::
      deployedResource (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ArtifactDeploymentDescription::Type::deployedResource_const_iterator b (o.begin_deployedResource()), e (o.end_deployedResource());

        if (b != e)
        {
          deployedResource_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) deployedResource_next (o);
          }

          deployedResource_post (o);
        }

        else deployedResource_none (o);
      }

      void ArtifactDeploymentDescription::
      deployedResource_pre (Type&)
      {
      }

      void ArtifactDeploymentDescription::
      deployedResource_pre (Type const&)
      {
      }

      void ArtifactDeploymentDescription::
      deployedResource_next (Type&)
      {
      }

      void ArtifactDeploymentDescription::
      deployedResource_next (Type const&)
      {
      }

      void ArtifactDeploymentDescription::
      deployedResource_post (Type&)
      {
      }

      void ArtifactDeploymentDescription::
      deployedResource_post (Type const&)
      {
      }

      void ArtifactDeploymentDescription::
      deployedResource_none (Type&)
      {
      }

      void ArtifactDeploymentDescription::
      deployedResource_none (Type const&)
      {
      }

      void ArtifactDeploymentDescription::
      id (Type& o)
      {
        dispatch (o.id ());
      }

      void ArtifactDeploymentDescription::
      id (Type const& o)
      {
        dispatch (o.id ());
      }

      void ArtifactDeploymentDescription::
      id_none (Type&)
      {
      }

      void ArtifactDeploymentDescription::
      id_none (Type const&)
      {
      }

      void ArtifactDeploymentDescription::
      post (Type&)
      {
      }

      void ArtifactDeploymentDescription::
      post (Type const&)
      {
      }

      // MonolithicDeploymentDescription
      //
      //

      void MonolithicDeploymentDescription::
      traverse (Type& o)
      {
        pre (o);
        name (o);
        source (o);
        artifact (o);
        execParameter (o);
        deployRequirement (o);
        if (o.id_p ()) id (o);
        else id_none (o);
        post (o);
      }

      void MonolithicDeploymentDescription::
      traverse (Type const& o)
      {
        pre (o);
        name (o);
        source (o);
        artifact (o);
        execParameter (o);
        deployRequirement (o);
        if (o.id_p ()) id (o);
        else id_none (o);
        post (o);
      }

      void MonolithicDeploymentDescription::
      pre (Type&)
      {
      }

      void MonolithicDeploymentDescription::
      pre (Type const&)
      {
      }

      void MonolithicDeploymentDescription::
      name (Type& o)
      {
        dispatch (o.name ());
      }

      void MonolithicDeploymentDescription::
      name (Type const& o)
      {
        dispatch (o.name ());
      }

      void MonolithicDeploymentDescription::
      source (Type& o)
      {
        // VC6 anathema strikes again
        //
        MonolithicDeploymentDescription::Type::source_iterator b (o.begin_source()), e (o.end_source());

        if (b != e)
        {
          source_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) source_next (o);
          }

          source_post (o);
        }
      }

      void MonolithicDeploymentDescription::
      source (Type const& o)
      {
        // VC6 anathema strikes again
        //
        MonolithicDeploymentDescription::Type::source_const_iterator b (o.begin_source()), e (o.end_source());

        if (b != e)
        {
          source_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) source_next (o);
          }

          source_post (o);
        }
      }

      void MonolithicDeploymentDescription::
      source_pre (Type&)
      {
      }

      void MonolithicDeploymentDescription::
      source_pre (Type const&)
      {
      }

      void MonolithicDeploymentDescription::
      source_next (Type&)
      {
      }

      void MonolithicDeploymentDescription::
      source_next (Type const&)
      {
      }

      void MonolithicDeploymentDescription::
      source_post (Type&)
      {
      }

      void MonolithicDeploymentDescription::
      source_post (Type const&)
      {
      }

      void MonolithicDeploymentDescription::
      artifact (Type& o)
      {
        // VC6 anathema strikes again
        //
        MonolithicDeploymentDescription::Type::artifact_iterator b (o.begin_artifact()), e (o.end_artifact());

        if (b != e)
        {
          artifact_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) artifact_next (o);
          }

          artifact_post (o);
        }
      }

      void MonolithicDeploymentDescription::
      artifact (Type const& o)
      {
        // VC6 anathema strikes again
        //
        MonolithicDeploymentDescription::Type::artifact_const_iterator b (o.begin_artifact()), e (o.end_artifact());

        if (b != e)
        {
          artifact_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) artifact_next (o);
          }

          artifact_post (o);
        }
      }

      void MonolithicDeploymentDescription::
      artifact_pre (Type&)
      {
      }

      void MonolithicDeploymentDescription::
      artifact_pre (Type const&)
      {
      }

      void MonolithicDeploymentDescription::
      artifact_next (Type&)
      {
      }

      void MonolithicDeploymentDescription::
      artifact_next (Type const&)
      {
      }

      void MonolithicDeploymentDescription::
      artifact_post (Type&)
      {
      }

      void MonolithicDeploymentDescription::
      artifact_post (Type const&)
      {
      }

      void MonolithicDeploymentDescription::
      execParameter (Type& o)
      {
        // VC6 anathema strikes again
        //
        MonolithicDeploymentDescription::Type::execParameter_iterator b (o.begin_execParameter()), e (o.end_execParameter());

        if (b != e)
        {
          execParameter_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) execParameter_next (o);
          }

          execParameter_post (o);
        }

        else execParameter_none (o);
      }

      void MonolithicDeploymentDescription::
      execParameter (Type const& o)
      {
        // VC6 anathema strikes again
        //
        MonolithicDeploymentDescription::Type::execParameter_const_iterator b (o.begin_execParameter()), e (o.end_execParameter());

        if (b != e)
        {
          execParameter_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) execParameter_next (o);
          }

          execParameter_post (o);
        }

        else execParameter_none (o);
      }

      void MonolithicDeploymentDescription::
      execParameter_pre (Type&)
      {
      }

      void MonolithicDeploymentDescription::
      execParameter_pre (Type const&)
      {
      }

      void MonolithicDeploymentDescription::
      execParameter_next (Type&)
      {
      }

      void MonolithicDeploymentDescription::
      execParameter_next (Type const&)
      {
      }

      void MonolithicDeploymentDescription::
      execParameter_post (Type&)
      {
      }

      void MonolithicDeploymentDescription::
      execParameter_post (Type const&)
      {
      }

      void MonolithicDeploymentDescription::
      execParameter_none (Type&)
      {
      }

      void MonolithicDeploymentDescription::
      execParameter_none (Type const&)
      {
      }

      void MonolithicDeploymentDescription::
      deployRequirement (Type& o)
      {
        // VC6 anathema strikes again
        //
        MonolithicDeploymentDescription::Type::deployRequirement_iterator b (o.begin_deployRequirement()), e (o.end_deployRequirement());

        if (b != e)
        {
          deployRequirement_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) deployRequirement_next (o);
          }

          deployRequirement_post (o);
        }

        else deployRequirement_none (o);
      }

      void MonolithicDeploymentDescription::
      deployRequirement (Type const& o)
      {
        // VC6 anathema strikes again
        //
        MonolithicDeploymentDescription::Type::deployRequirement_const_iterator b (o.begin_deployRequirement()), e (o.end_deployRequirement());

        if (b != e)
        {
          deployRequirement_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) deployRequirement_next (o);
          }

          deployRequirement_post (o);
        }

        else deployRequirement_none (o);
      }

      void MonolithicDeploymentDescription::
      deployRequirement_pre (Type&)
      {
      }

      void MonolithicDeploymentDescription::
      deployRequirement_pre (Type const&)
      {
      }

      void MonolithicDeploymentDescription::
      deployRequirement_next (Type&)
      {
      }

      void MonolithicDeploymentDescription::
      deployRequirement_next (Type const&)
      {
      }

      void MonolithicDeploymentDescription::
      deployRequirement_post (Type&)
      {
      }

      void MonolithicDeploymentDescription::
      deployRequirement_post (Type const&)
      {
      }

      void MonolithicDeploymentDescription::
      deployRequirement_none (Type&)
      {
      }

      void MonolithicDeploymentDescription::
      deployRequirement_none (Type const&)
      {
      }

      void MonolithicDeploymentDescription::
      id (Type& o)
      {
        dispatch (o.id ());
      }

      void MonolithicDeploymentDescription::
      id (Type const& o)
      {
        dispatch (o.id ());
      }

      void MonolithicDeploymentDescription::
      id_none (Type&)
      {
      }

      void MonolithicDeploymentDescription::
      id_none (Type const&)
      {
      }

      void MonolithicDeploymentDescription::
      post (Type&)
      {
      }

      void MonolithicDeploymentDescription::
      post (Type const&)
      {
      }

      // InstanceResourceDeploymentDescription
      //
      //

      void InstanceResourceDeploymentDescription::
      traverse (Type& o)
      {
        pre (o);
        resourceUsage (o);
        requirementName (o);
        resourceName (o);
        property (o);
        post (o);
      }

      void InstanceResourceDeploymentDescription::
      traverse (Type const& o)
      {
        pre (o);
        resourceUsage (o);
        requirementName (o);
        resourceName (o);
        property (o);
        post (o);
      }

      void InstanceResourceDeploymentDescription::
      pre (Type&)
      {
      }

      void InstanceResourceDeploymentDescription::
      pre (Type const&)
      {
      }

      void InstanceResourceDeploymentDescription::
      resourceUsage (Type& o)
      {
        dispatch (o.resourceUsage ());
      }

      void InstanceResourceDeploymentDescription::
      resourceUsage (Type const& o)
      {
        dispatch (o.resourceUsage ());
      }

      void InstanceResourceDeploymentDescription::
      requirementName (Type& o)
      {
        dispatch (o.requirementName ());
      }

      void InstanceResourceDeploymentDescription::
      requirementName (Type const& o)
      {
        dispatch (o.requirementName ());
      }

      void InstanceResourceDeploymentDescription::
      resourceName (Type& o)
      {
        dispatch (o.resourceName ());
      }

      void InstanceResourceDeploymentDescription::
      resourceName (Type const& o)
      {
        dispatch (o.resourceName ());
      }

      void InstanceResourceDeploymentDescription::
      property (Type& o)
      {
        // VC6 anathema strikes again
        //
        InstanceResourceDeploymentDescription::Type::property_iterator b (o.begin_property()), e (o.end_property());

        if (b != e)
        {
          property_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) property_next (o);
          }

          property_post (o);
        }

        else property_none (o);
      }

      void InstanceResourceDeploymentDescription::
      property (Type const& o)
      {
        // VC6 anathema strikes again
        //
        InstanceResourceDeploymentDescription::Type::property_const_iterator b (o.begin_property()), e (o.end_property());

        if (b != e)
        {
          property_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) property_next (o);
          }

          property_post (o);
        }

        else property_none (o);
      }

      void InstanceResourceDeploymentDescription::
      property_pre (Type&)
      {
      }

      void InstanceResourceDeploymentDescription::
      property_pre (Type const&)
      {
      }

      void InstanceResourceDeploymentDescription::
      property_next (Type&)
      {
      }

      void InstanceResourceDeploymentDescription::
      property_next (Type const&)
      {
      }

      void InstanceResourceDeploymentDescription::
      property_post (Type&)
      {
      }

      void InstanceResourceDeploymentDescription::
      property_post (Type const&)
      {
      }

      void InstanceResourceDeploymentDescription::
      property_none (Type&)
      {
      }

      void InstanceResourceDeploymentDescription::
      property_none (Type const&)
      {
      }

      void InstanceResourceDeploymentDescription::
      post (Type&)
      {
      }

      void InstanceResourceDeploymentDescription::
      post (Type const&)
      {
      }

      // InstanceDeploymentDescription
      //
      //

      void InstanceDeploymentDescription::
      traverse (Type& o)
      {
        pre (o);
        name (o);
        node (o);
        source (o);
        implementation (o);
        configProperty (o);
        deployedResource (o);
        if (o.deployedSharedResource_p ()) deployedSharedResource (o);
        else deployedSharedResource_none (o);
        if (o.id_p ()) id (o);
        else id_none (o);
        post (o);
      }

      void InstanceDeploymentDescription::
      traverse (Type const& o)
      {
        pre (o);
        name (o);
        node (o);
        source (o);
        implementation (o);
        configProperty (o);
        deployedResource (o);
        if (o.deployedSharedResource_p ()) deployedSharedResource (o);
        else deployedSharedResource_none (o);
        if (o.id_p ()) id (o);
        else id_none (o);
        post (o);
      }

      void InstanceDeploymentDescription::
      pre (Type&)
      {
      }

      void InstanceDeploymentDescription::
      pre (Type const&)
      {
      }

      void InstanceDeploymentDescription::
      name (Type& o)
      {
        dispatch (o.name ());
      }

      void InstanceDeploymentDescription::
      name (Type const& o)
      {
        dispatch (o.name ());
      }

      void InstanceDeploymentDescription::
      node (Type& o)
      {
        dispatch (o.node ());
      }

      void InstanceDeploymentDescription::
      node (Type const& o)
      {
        dispatch (o.node ());
      }

      void InstanceDeploymentDescription::
      source (Type& o)
      {
        dispatch (o.source ());
      }

      void InstanceDeploymentDescription::
      source (Type const& o)
      {
        dispatch (o.source ());
      }

      void InstanceDeploymentDescription::
      implementation (Type& o)
      {
        dispatch (o.implementation ());
      }

      void InstanceDeploymentDescription::
      implementation (Type const& o)
      {
        dispatch (o.implementation ());
      }

      void InstanceDeploymentDescription::
      configProperty (Type& o)
      {
        // VC6 anathema strikes again
        //
        InstanceDeploymentDescription::Type::configProperty_iterator b (o.begin_configProperty()), e (o.end_configProperty());

        if (b != e)
        {
          configProperty_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) configProperty_next (o);
          }

          configProperty_post (o);
        }

        else configProperty_none (o);
      }

      void InstanceDeploymentDescription::
      configProperty (Type const& o)
      {
        // VC6 anathema strikes again
        //
        InstanceDeploymentDescription::Type::configProperty_const_iterator b (o.begin_configProperty()), e (o.end_configProperty());

        if (b != e)
        {
          configProperty_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) configProperty_next (o);
          }

          configProperty_post (o);
        }

        else configProperty_none (o);
      }

      void InstanceDeploymentDescription::
      configProperty_pre (Type&)
      {
      }

      void InstanceDeploymentDescription::
      configProperty_pre (Type const&)
      {
      }

      void InstanceDeploymentDescription::
      configProperty_next (Type&)
      {
      }

      void InstanceDeploymentDescription::
      configProperty_next (Type const&)
      {
      }

      void InstanceDeploymentDescription::
      configProperty_post (Type&)
      {
      }

      void InstanceDeploymentDescription::
      configProperty_post (Type const&)
      {
      }

      void InstanceDeploymentDescription::
      configProperty_none (Type&)
      {
      }

      void InstanceDeploymentDescription::
      configProperty_none (Type const&)
      {
      }

      void InstanceDeploymentDescription::
      deployedResource (Type& o)
      {
        // VC6 anathema strikes again
        //
        InstanceDeploymentDescription::Type::deployedResource_iterator b (o.begin_deployedResource()), e (o.end_deployedResource());

        if (b != e)
        {
          deployedResource_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) deployedResource_next (o);
          }

          deployedResource_post (o);
        }

        else deployedResource_none (o);
      }

      void InstanceDeploymentDescription::
      deployedResource (Type const& o)
      {
        // VC6 anathema strikes again
        //
        InstanceDeploymentDescription::Type::deployedResource_const_iterator b (o.begin_deployedResource()), e (o.end_deployedResource());

        if (b != e)
        {
          deployedResource_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) deployedResource_next (o);
          }

          deployedResource_post (o);
        }

        else deployedResource_none (o);
      }

      void InstanceDeploymentDescription::
      deployedResource_pre (Type&)
      {
      }

      void InstanceDeploymentDescription::
      deployedResource_pre (Type const&)
      {
      }

      void InstanceDeploymentDescription::
      deployedResource_next (Type&)
      {
      }

      void InstanceDeploymentDescription::
      deployedResource_next (Type const&)
      {
      }

      void InstanceDeploymentDescription::
      deployedResource_post (Type&)
      {
      }

      void InstanceDeploymentDescription::
      deployedResource_post (Type const&)
      {
      }

      void InstanceDeploymentDescription::
      deployedResource_none (Type&)
      {
      }

      void InstanceDeploymentDescription::
      deployedResource_none (Type const&)
      {
      }

      void InstanceDeploymentDescription::
      deployedSharedResource (Type& o)
      {
        dispatch (o.deployedSharedResource ());
      }

      void InstanceDeploymentDescription::
      deployedSharedResource (Type const& o)
      {
        dispatch (o.deployedSharedResource ());
      }

      void InstanceDeploymentDescription::
      deployedSharedResource_none (Type&)
      {
      }

      void InstanceDeploymentDescription::
      deployedSharedResource_none (Type const&)
      {
      }

      void InstanceDeploymentDescription::
      id (Type& o)
      {
        dispatch (o.id ());
      }

      void InstanceDeploymentDescription::
      id (Type const& o)
      {
        dispatch (o.id ());
      }

      void InstanceDeploymentDescription::
      id_none (Type&)
      {
      }

      void InstanceDeploymentDescription::
      id_none (Type const&)
      {
      }

      void InstanceDeploymentDescription::
      post (Type&)
      {
      }

      void InstanceDeploymentDescription::
      post (Type const&)
      {
      }

      // ComponentPortDescription
      //
      //

      void ComponentPortDescription::
      traverse (Type& o)
      {
        pre (o);
        name (o);
        if (o.specificType_p ()) specificType (o);
        else specificType_none (o);
        supportedType (o);
        provider (o);
        exclusiveProvider (o);
        exclusiveUser (o);
        optional (o);
        kind (o);
        post (o);
      }

      void ComponentPortDescription::
      traverse (Type const& o)
      {
        pre (o);
        name (o);
        if (o.specificType_p ()) specificType (o);
        else specificType_none (o);
        supportedType (o);
        provider (o);
        exclusiveProvider (o);
        exclusiveUser (o);
        optional (o);
        kind (o);
        post (o);
      }

      void ComponentPortDescription::
      pre (Type&)
      {
      }

      void ComponentPortDescription::
      pre (Type const&)
      {
      }

      void ComponentPortDescription::
      name (Type& o)
      {
        dispatch (o.name ());
      }

      void ComponentPortDescription::
      name (Type const& o)
      {
        dispatch (o.name ());
      }

      void ComponentPortDescription::
      specificType (Type& o)
      {
        dispatch (o.specificType ());
      }

      void ComponentPortDescription::
      specificType (Type const& o)
      {
        dispatch (o.specificType ());
      }

      void ComponentPortDescription::
      specificType_none (Type&)
      {
      }

      void ComponentPortDescription::
      specificType_none (Type const&)
      {
      }

      void ComponentPortDescription::
      supportedType (Type& o)
      {
        // VC6 anathema strikes again
        //
        ComponentPortDescription::Type::supportedType_iterator b (o.begin_supportedType()), e (o.end_supportedType());

        if (b != e)
        {
          supportedType_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) supportedType_next (o);
          }

          supportedType_post (o);
        }

        else supportedType_none (o);
      }

      void ComponentPortDescription::
      supportedType (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ComponentPortDescription::Type::supportedType_const_iterator b (o.begin_supportedType()), e (o.end_supportedType());

        if (b != e)
        {
          supportedType_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) supportedType_next (o);
          }

          supportedType_post (o);
        }

        else supportedType_none (o);
      }

      void ComponentPortDescription::
      supportedType_pre (Type&)
      {
      }

      void ComponentPortDescription::
      supportedType_pre (Type const&)
      {
      }

      void ComponentPortDescription::
      supportedType_next (Type&)
      {
      }

      void ComponentPortDescription::
      supportedType_next (Type const&)
      {
      }

      void ComponentPortDescription::
      supportedType_post (Type&)
      {
      }

      void ComponentPortDescription::
      supportedType_post (Type const&)
      {
      }

      void ComponentPortDescription::
      supportedType_none (Type&)
      {
      }

      void ComponentPortDescription::
      supportedType_none (Type const&)
      {
      }

      void ComponentPortDescription::
      provider (Type& o)
      {
        dispatch (o.provider ());
      }

      void ComponentPortDescription::
      provider (Type const& o)
      {
        dispatch (o.provider ());
      }

      void ComponentPortDescription::
      exclusiveProvider (Type& o)
      {
        dispatch (o.exclusiveProvider ());
      }

      void ComponentPortDescription::
      exclusiveProvider (Type const& o)
      {
        dispatch (o.exclusiveProvider ());
      }

      void ComponentPortDescription::
      exclusiveUser (Type& o)
      {
        dispatch (o.exclusiveUser ());
      }

      void ComponentPortDescription::
      exclusiveUser (Type const& o)
      {
        dispatch (o.exclusiveUser ());
      }

      void ComponentPortDescription::
      optional (Type& o)
      {
        dispatch (o.optional ());
      }

      void ComponentPortDescription::
      optional (Type const& o)
      {
        dispatch (o.optional ());
      }

      void ComponentPortDescription::
      kind (Type& o)
      {
        dispatch (o.kind ());
      }

      void ComponentPortDescription::
      kind (Type const& o)
      {
        dispatch (o.kind ());
      }

      void ComponentPortDescription::
      post (Type&)
      {
      }

      void ComponentPortDescription::
      post (Type const&)
      {
      }

      // ComponentPropertyDescription
      //
      //

      void ComponentPropertyDescription::
      traverse (Type& o)
      {
        pre (o);
        name (o);
        type (o);
        post (o);
      }

      void ComponentPropertyDescription::
      traverse (Type const& o)
      {
        pre (o);
        name (o);
        type (o);
        post (o);
      }

      void ComponentPropertyDescription::
      pre (Type&)
      {
      }

      void ComponentPropertyDescription::
      pre (Type const&)
      {
      }

      void ComponentPropertyDescription::
      name (Type& o)
      {
        dispatch (o.name ());
      }

      void ComponentPropertyDescription::
      name (Type const& o)
      {
        dispatch (o.name ());
      }

      void ComponentPropertyDescription::
      type (Type& o)
      {
        dispatch (o.type ());
      }

      void ComponentPropertyDescription::
      type (Type const& o)
      {
        dispatch (o.type ());
      }

      void ComponentPropertyDescription::
      post (Type&)
      {
      }

      void ComponentPropertyDescription::
      post (Type const&)
      {
      }

      // ComponentExternalPortEndpoint
      //
      //

      void ComponentExternalPortEndpoint::
      traverse (Type& o)
      {
        pre (o);
        portName (o);
        post (o);
      }

      void ComponentExternalPortEndpoint::
      traverse (Type const& o)
      {
        pre (o);
        portName (o);
        post (o);
      }

      void ComponentExternalPortEndpoint::
      pre (Type&)
      {
      }

      void ComponentExternalPortEndpoint::
      pre (Type const&)
      {
      }

      void ComponentExternalPortEndpoint::
      portName (Type& o)
      {
        dispatch (o.portName ());
      }

      void ComponentExternalPortEndpoint::
      portName (Type const& o)
      {
        dispatch (o.portName ());
      }

      void ComponentExternalPortEndpoint::
      post (Type&)
      {
      }

      void ComponentExternalPortEndpoint::
      post (Type const&)
      {
      }

      // PlanSubcomponentPortEndpoint
      //
      //

      void PlanSubcomponentPortEndpoint::
      traverse (Type& o)
      {
        pre (o);
        portName (o);
        if (o.provider_p ()) provider (o);
        else provider_none (o);
        kind (o);
        instance (o);
        post (o);
      }

      void PlanSubcomponentPortEndpoint::
      traverse (Type const& o)
      {
        pre (o);
        portName (o);
        if (o.provider_p ()) provider (o);
        else provider_none (o);
        kind (o);
        instance (o);
        post (o);
      }

      void PlanSubcomponentPortEndpoint::
      pre (Type&)
      {
      }

      void PlanSubcomponentPortEndpoint::
      pre (Type const&)
      {
      }

      void PlanSubcomponentPortEndpoint::
      portName (Type& o)
      {
        dispatch (o.portName ());
      }

      void PlanSubcomponentPortEndpoint::
      portName (Type const& o)
      {
        dispatch (o.portName ());
      }

      void PlanSubcomponentPortEndpoint::
      provider (Type& o)
      {
        dispatch (o.provider ());
      }

      void PlanSubcomponentPortEndpoint::
      provider (Type const& o)
      {
        dispatch (o.provider ());
      }

      void PlanSubcomponentPortEndpoint::
      provider_none (Type&)
      {
      }

      void PlanSubcomponentPortEndpoint::
      provider_none (Type const&)
      {
      }

      void PlanSubcomponentPortEndpoint::
      kind (Type& o)
      {
        dispatch (o.kind ());
      }

      void PlanSubcomponentPortEndpoint::
      kind (Type const& o)
      {
        dispatch (o.kind ());
      }

      void PlanSubcomponentPortEndpoint::
      instance (Type& o)
      {
        dispatch (o.instance ());
      }

      void PlanSubcomponentPortEndpoint::
      instance (Type const& o)
      {
        dispatch (o.instance ());
      }

      void PlanSubcomponentPortEndpoint::
      post (Type&)
      {
      }

      void PlanSubcomponentPortEndpoint::
      post (Type const&)
      {
      }

      // ExternalReferenceEndpoint
      //
      //

      void ExternalReferenceEndpoint::
      traverse (Type& o)
      {
        pre (o);
        location (o);
        post (o);
      }

      void ExternalReferenceEndpoint::
      traverse (Type const& o)
      {
        pre (o);
        location (o);
        post (o);
      }

      void ExternalReferenceEndpoint::
      pre (Type&)
      {
      }

      void ExternalReferenceEndpoint::
      pre (Type const&)
      {
      }

      void ExternalReferenceEndpoint::
      location (Type& o)
      {
        dispatch (o.location ());
      }

      void ExternalReferenceEndpoint::
      location (Type const& o)
      {
        dispatch (o.location ());
      }

      void ExternalReferenceEndpoint::
      post (Type&)
      {
      }

      void ExternalReferenceEndpoint::
      post (Type const&)
      {
      }

      // ConnectionResourceDeploymentDescription
      //
      //

      void ConnectionResourceDeploymentDescription::
      traverse (Type& o)
      {
        pre (o);
        targetName (o);
        requirementName (o);
        resourceName (o);
        property (o);
        post (o);
      }

      void ConnectionResourceDeploymentDescription::
      traverse (Type const& o)
      {
        pre (o);
        targetName (o);
        requirementName (o);
        resourceName (o);
        property (o);
        post (o);
      }

      void ConnectionResourceDeploymentDescription::
      pre (Type&)
      {
      }

      void ConnectionResourceDeploymentDescription::
      pre (Type const&)
      {
      }

      void ConnectionResourceDeploymentDescription::
      targetName (Type& o)
      {
        dispatch (o.targetName ());
      }

      void ConnectionResourceDeploymentDescription::
      targetName (Type const& o)
      {
        dispatch (o.targetName ());
      }

      void ConnectionResourceDeploymentDescription::
      requirementName (Type& o)
      {
        dispatch (o.requirementName ());
      }

      void ConnectionResourceDeploymentDescription::
      requirementName (Type const& o)
      {
        dispatch (o.requirementName ());
      }

      void ConnectionResourceDeploymentDescription::
      resourceName (Type& o)
      {
        dispatch (o.resourceName ());
      }

      void ConnectionResourceDeploymentDescription::
      resourceName (Type const& o)
      {
        dispatch (o.resourceName ());
      }

      void ConnectionResourceDeploymentDescription::
      property (Type& o)
      {
        // VC6 anathema strikes again
        //
        ConnectionResourceDeploymentDescription::Type::property_iterator b (o.begin_property()), e (o.end_property());

        if (b != e)
        {
          property_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) property_next (o);
          }

          property_post (o);
        }

        else property_none (o);
      }

      void ConnectionResourceDeploymentDescription::
      property (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ConnectionResourceDeploymentDescription::Type::property_const_iterator b (o.begin_property()), e (o.end_property());

        if (b != e)
        {
          property_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) property_next (o);
          }

          property_post (o);
        }

        else property_none (o);
      }

      void ConnectionResourceDeploymentDescription::
      property_pre (Type&)
      {
      }

      void ConnectionResourceDeploymentDescription::
      property_pre (Type const&)
      {
      }

      void ConnectionResourceDeploymentDescription::
      property_next (Type&)
      {
      }

      void ConnectionResourceDeploymentDescription::
      property_next (Type const&)
      {
      }

      void ConnectionResourceDeploymentDescription::
      property_post (Type&)
      {
      }

      void ConnectionResourceDeploymentDescription::
      property_post (Type const&)
      {
      }

      void ConnectionResourceDeploymentDescription::
      property_none (Type&)
      {
      }

      void ConnectionResourceDeploymentDescription::
      property_none (Type const&)
      {
      }

      void ConnectionResourceDeploymentDescription::
      post (Type&)
      {
      }

      void ConnectionResourceDeploymentDescription::
      post (Type const&)
      {
      }

      // PlanConnectionDescription
      //
      //

      void PlanConnectionDescription::
      traverse (Type& o)
      {
        pre (o);
        name (o);
        if (o.source_p ()) source (o);
        else source_none (o);
        deployRequirement (o);
        externalEndpoint (o);
        internalEndpoint (o);
        externalReference (o);
        deployedResource (o);
        post (o);
      }

      void PlanConnectionDescription::
      traverse (Type const& o)
      {
        pre (o);
        name (o);
        if (o.source_p ()) source (o);
        else source_none (o);
        deployRequirement (o);
        externalEndpoint (o);
        internalEndpoint (o);
        externalReference (o);
        deployedResource (o);
        post (o);
      }

      void PlanConnectionDescription::
      pre (Type&)
      {
      }

      void PlanConnectionDescription::
      pre (Type const&)
      {
      }

      void PlanConnectionDescription::
      name (Type& o)
      {
        dispatch (o.name ());
      }

      void PlanConnectionDescription::
      name (Type const& o)
      {
        dispatch (o.name ());
      }

      void PlanConnectionDescription::
      source (Type& o)
      {
        dispatch (o.source ());
      }

      void PlanConnectionDescription::
      source (Type const& o)
      {
        dispatch (o.source ());
      }

      void PlanConnectionDescription::
      source_none (Type&)
      {
      }

      void PlanConnectionDescription::
      source_none (Type const&)
      {
      }

      void PlanConnectionDescription::
      deployRequirement (Type& o)
      {
        // VC6 anathema strikes again
        //
        PlanConnectionDescription::Type::deployRequirement_iterator b (o.begin_deployRequirement()), e (o.end_deployRequirement());

        if (b != e)
        {
          deployRequirement_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) deployRequirement_next (o);
          }

          deployRequirement_post (o);
        }

        else deployRequirement_none (o);
      }

      void PlanConnectionDescription::
      deployRequirement (Type const& o)
      {
        // VC6 anathema strikes again
        //
        PlanConnectionDescription::Type::deployRequirement_const_iterator b (o.begin_deployRequirement()), e (o.end_deployRequirement());

        if (b != e)
        {
          deployRequirement_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) deployRequirement_next (o);
          }

          deployRequirement_post (o);
        }

        else deployRequirement_none (o);
      }

      void PlanConnectionDescription::
      deployRequirement_pre (Type&)
      {
      }

      void PlanConnectionDescription::
      deployRequirement_pre (Type const&)
      {
      }

      void PlanConnectionDescription::
      deployRequirement_next (Type&)
      {
      }

      void PlanConnectionDescription::
      deployRequirement_next (Type const&)
      {
      }

      void PlanConnectionDescription::
      deployRequirement_post (Type&)
      {
      }

      void PlanConnectionDescription::
      deployRequirement_post (Type const&)
      {
      }

      void PlanConnectionDescription::
      deployRequirement_none (Type&)
      {
      }

      void PlanConnectionDescription::
      deployRequirement_none (Type const&)
      {
      }

      void PlanConnectionDescription::
      externalEndpoint (Type& o)
      {
        // VC6 anathema strikes again
        //
        PlanConnectionDescription::Type::externalEndpoint_iterator b (o.begin_externalEndpoint()), e (o.end_externalEndpoint());

        if (b != e)
        {
          externalEndpoint_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) externalEndpoint_next (o);
          }

          externalEndpoint_post (o);
        }

        else externalEndpoint_none (o);
      }

      void PlanConnectionDescription::
      externalEndpoint (Type const& o)
      {
        // VC6 anathema strikes again
        //
        PlanConnectionDescription::Type::externalEndpoint_const_iterator b (o.begin_externalEndpoint()), e (o.end_externalEndpoint());

        if (b != e)
        {
          externalEndpoint_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) externalEndpoint_next (o);
          }

          externalEndpoint_post (o);
        }

        else externalEndpoint_none (o);
      }

      void PlanConnectionDescription::
      externalEndpoint_pre (Type&)
      {
      }

      void PlanConnectionDescription::
      externalEndpoint_pre (Type const&)
      {
      }

      void PlanConnectionDescription::
      externalEndpoint_next (Type&)
      {
      }

      void PlanConnectionDescription::
      externalEndpoint_next (Type const&)
      {
      }

      void PlanConnectionDescription::
      externalEndpoint_post (Type&)
      {
      }

      void PlanConnectionDescription::
      externalEndpoint_post (Type const&)
      {
      }

      void PlanConnectionDescription::
      externalEndpoint_none (Type&)
      {
      }

      void PlanConnectionDescription::
      externalEndpoint_none (Type const&)
      {
      }

      void PlanConnectionDescription::
      internalEndpoint (Type& o)
      {
        // VC6 anathema strikes again
        //
        PlanConnectionDescription::Type::internalEndpoint_iterator b (o.begin_internalEndpoint()), e (o.end_internalEndpoint());

        if (b != e)
        {
          internalEndpoint_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) internalEndpoint_next (o);
          }

          internalEndpoint_post (o);
        }

        else internalEndpoint_none (o);
      }

      void PlanConnectionDescription::
      internalEndpoint (Type const& o)
      {
        // VC6 anathema strikes again
        //
        PlanConnectionDescription::Type::internalEndpoint_const_iterator b (o.begin_internalEndpoint()), e (o.end_internalEndpoint());

        if (b != e)
        {
          internalEndpoint_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) internalEndpoint_next (o);
          }

          internalEndpoint_post (o);
        }

        else internalEndpoint_none (o);
      }

      void PlanConnectionDescription::
      internalEndpoint_pre (Type&)
      {
      }

      void PlanConnectionDescription::
      internalEndpoint_pre (Type const&)
      {
      }

      void PlanConnectionDescription::
      internalEndpoint_next (Type&)
      {
      }

      void PlanConnectionDescription::
      internalEndpoint_next (Type const&)
      {
      }

      void PlanConnectionDescription::
      internalEndpoint_post (Type&)
      {
      }

      void PlanConnectionDescription::
      internalEndpoint_post (Type const&)
      {
      }

      void PlanConnectionDescription::
      internalEndpoint_none (Type&)
      {
      }

      void PlanConnectionDescription::
      internalEndpoint_none (Type const&)
      {
      }

      void PlanConnectionDescription::
      externalReference (Type& o)
      {
        // VC6 anathema strikes again
        //
        PlanConnectionDescription::Type::externalReference_iterator b (o.begin_externalReference()), e (o.end_externalReference());

        if (b != e)
        {
          externalReference_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) externalReference_next (o);
          }

          externalReference_post (o);
        }

        else externalReference_none (o);
      }

      void PlanConnectionDescription::
      externalReference (Type const& o)
      {
        // VC6 anathema strikes again
        //
        PlanConnectionDescription::Type::externalReference_const_iterator b (o.begin_externalReference()), e (o.end_externalReference());

        if (b != e)
        {
          externalReference_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) externalReference_next (o);
          }

          externalReference_post (o);
        }

        else externalReference_none (o);
      }

      void PlanConnectionDescription::
      externalReference_pre (Type&)
      {
      }

      void PlanConnectionDescription::
      externalReference_pre (Type const&)
      {
      }

      void PlanConnectionDescription::
      externalReference_next (Type&)
      {
      }

      void PlanConnectionDescription::
      externalReference_next (Type const&)
      {
      }

      void PlanConnectionDescription::
      externalReference_post (Type&)
      {
      }

      void PlanConnectionDescription::
      externalReference_post (Type const&)
      {
      }

      void PlanConnectionDescription::
      externalReference_none (Type&)
      {
      }

      void PlanConnectionDescription::
      externalReference_none (Type const&)
      {
      }

      void PlanConnectionDescription::
      deployedResource (Type& o)
      {
        // VC6 anathema strikes again
        //
        PlanConnectionDescription::Type::deployedResource_iterator b (o.begin_deployedResource()), e (o.end_deployedResource());

        if (b != e)
        {
          deployedResource_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) deployedResource_next (o);
          }

          deployedResource_post (o);
        }

        else deployedResource_none (o);
      }

      void PlanConnectionDescription::
      deployedResource (Type const& o)
      {
        // VC6 anathema strikes again
        //
        PlanConnectionDescription::Type::deployedResource_const_iterator b (o.begin_deployedResource()), e (o.end_deployedResource());

        if (b != e)
        {
          deployedResource_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) deployedResource_next (o);
          }

          deployedResource_post (o);
        }

        else deployedResource_none (o);
      }

      void PlanConnectionDescription::
      deployedResource_pre (Type&)
      {
      }

      void PlanConnectionDescription::
      deployedResource_pre (Type const&)
      {
      }

      void PlanConnectionDescription::
      deployedResource_next (Type&)
      {
      }

      void PlanConnectionDescription::
      deployedResource_next (Type const&)
      {
      }

      void PlanConnectionDescription::
      deployedResource_post (Type&)
      {
      }

      void PlanConnectionDescription::
      deployedResource_post (Type const&)
      {
      }

      void PlanConnectionDescription::
      deployedResource_none (Type&)
      {
      }

      void PlanConnectionDescription::
      deployedResource_none (Type const&)
      {
      }

      void PlanConnectionDescription::
      post (Type&)
      {
      }

      void PlanConnectionDescription::
      post (Type const&)
      {
      }

      // ImplementationDependency
      //
      //

      void ImplementationDependency::
      traverse (Type& o)
      {
        pre (o);
        requiredType (o);
        post (o);
      }

      void ImplementationDependency::
      traverse (Type const& o)
      {
        pre (o);
        requiredType (o);
        post (o);
      }

      void ImplementationDependency::
      pre (Type&)
      {
      }

      void ImplementationDependency::
      pre (Type const&)
      {
      }

      void ImplementationDependency::
      requiredType (Type& o)
      {
        dispatch (o.requiredType ());
      }

      void ImplementationDependency::
      requiredType (Type const& o)
      {
        dispatch (o.requiredType ());
      }

      void ImplementationDependency::
      post (Type&)
      {
      }

      void ImplementationDependency::
      post (Type const&)
      {
      }

      // Capability
      //
      //

      void Capability::
      traverse (Type& o)
      {
        pre (o);
        name (o);
        resourceType (o);
        property (o);
        post (o);
      }

      void Capability::
      traverse (Type const& o)
      {
        pre (o);
        name (o);
        resourceType (o);
        property (o);
        post (o);
      }

      void Capability::
      pre (Type&)
      {
      }

      void Capability::
      pre (Type const&)
      {
      }

      void Capability::
      name (Type& o)
      {
        dispatch (o.name ());
      }

      void Capability::
      name (Type const& o)
      {
        dispatch (o.name ());
      }

      void Capability::
      resourceType (Type& o)
      {
        // VC6 anathema strikes again
        //
        Capability::Type::resourceType_iterator b (o.begin_resourceType()), e (o.end_resourceType());

        if (b != e)
        {
          resourceType_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) resourceType_next (o);
          }

          resourceType_post (o);
        }
      }

      void Capability::
      resourceType (Type const& o)
      {
        // VC6 anathema strikes again
        //
        Capability::Type::resourceType_const_iterator b (o.begin_resourceType()), e (o.end_resourceType());

        if (b != e)
        {
          resourceType_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) resourceType_next (o);
          }

          resourceType_post (o);
        }
      }

      void Capability::
      resourceType_pre (Type&)
      {
      }

      void Capability::
      resourceType_pre (Type const&)
      {
      }

      void Capability::
      resourceType_next (Type&)
      {
      }

      void Capability::
      resourceType_next (Type const&)
      {
      }

      void Capability::
      resourceType_post (Type&)
      {
      }

      void Capability::
      resourceType_post (Type const&)
      {
      }

      void Capability::
      property (Type& o)
      {
        // VC6 anathema strikes again
        //
        Capability::Type::property_iterator b (o.begin_property()), e (o.end_property());

        if (b != e)
        {
          property_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) property_next (o);
          }

          property_post (o);
        }

        else property_none (o);
      }

      void Capability::
      property (Type const& o)
      {
        // VC6 anathema strikes again
        //
        Capability::Type::property_const_iterator b (o.begin_property()), e (o.end_property());

        if (b != e)
        {
          property_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) property_next (o);
          }

          property_post (o);
        }

        else property_none (o);
      }

      void Capability::
      property_pre (Type&)
      {
      }

      void Capability::
      property_pre (Type const&)
      {
      }

      void Capability::
      property_next (Type&)
      {
      }

      void Capability::
      property_next (Type const&)
      {
      }

      void Capability::
      property_post (Type&)
      {
      }

      void Capability::
      property_post (Type const&)
      {
      }

      void Capability::
      property_none (Type&)
      {
      }

      void Capability::
      property_none (Type const&)
      {
      }

      void Capability::
      post (Type&)
      {
      }

      void Capability::
      post (Type const&)
      {
      }

      // ImplementationRequirement
      //
      //

      void ImplementationRequirement::
      traverse (Type& o)
      {
        pre (o);
        if (o.resourceUsage_p ()) resourceUsage (o);
        else resourceUsage_none (o);
        if (o.resourcePort_p ()) resourcePort (o);
        else resourcePort_none (o);
        if (o.componentPort_p ()) componentPort (o);
        else componentPort_none (o);
        resourceType (o);
        name (o);
        property (o);
        post (o);
      }

      void ImplementationRequirement::
      traverse (Type const& o)
      {
        pre (o);
        if (o.resourceUsage_p ()) resourceUsage (o);
        else resourceUsage_none (o);
        if (o.resourcePort_p ()) resourcePort (o);
        else resourcePort_none (o);
        if (o.componentPort_p ()) componentPort (o);
        else componentPort_none (o);
        resourceType (o);
        name (o);
        property (o);
        post (o);
      }

      void ImplementationRequirement::
      pre (Type&)
      {
      }

      void ImplementationRequirement::
      pre (Type const&)
      {
      }

      void ImplementationRequirement::
      resourceUsage (Type& o)
      {
        dispatch (o.resourceUsage ());
      }

      void ImplementationRequirement::
      resourceUsage (Type const& o)
      {
        dispatch (o.resourceUsage ());
      }

      void ImplementationRequirement::
      resourceUsage_none (Type&)
      {
      }

      void ImplementationRequirement::
      resourceUsage_none (Type const&)
      {
      }

      void ImplementationRequirement::
      resourcePort (Type& o)
      {
        dispatch (o.resourcePort ());
      }

      void ImplementationRequirement::
      resourcePort (Type const& o)
      {
        dispatch (o.resourcePort ());
      }

      void ImplementationRequirement::
      resourcePort_none (Type&)
      {
      }

      void ImplementationRequirement::
      resourcePort_none (Type const&)
      {
      }

      void ImplementationRequirement::
      componentPort (Type& o)
      {
        dispatch (o.componentPort ());
      }

      void ImplementationRequirement::
      componentPort (Type const& o)
      {
        dispatch (o.componentPort ());
      }

      void ImplementationRequirement::
      componentPort_none (Type&)
      {
      }

      void ImplementationRequirement::
      componentPort_none (Type const&)
      {
      }

      void ImplementationRequirement::
      resourceType (Type& o)
      {
        dispatch (o.resourceType ());
      }

      void ImplementationRequirement::
      resourceType (Type const& o)
      {
        dispatch (o.resourceType ());
      }

      void ImplementationRequirement::
      name (Type& o)
      {
        dispatch (o.name ());
      }

      void ImplementationRequirement::
      name (Type const& o)
      {
        dispatch (o.name ());
      }

      void ImplementationRequirement::
      property (Type& o)
      {
        // VC6 anathema strikes again
        //
        ImplementationRequirement::Type::property_iterator b (o.begin_property()), e (o.end_property());

        if (b != e)
        {
          property_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) property_next (o);
          }

          property_post (o);
        }

        else property_none (o);
      }

      void ImplementationRequirement::
      property (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ImplementationRequirement::Type::property_const_iterator b (o.begin_property()), e (o.end_property());

        if (b != e)
        {
          property_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) property_next (o);
          }

          property_post (o);
        }

        else property_none (o);
      }

      void ImplementationRequirement::
      property_pre (Type&)
      {
      }

      void ImplementationRequirement::
      property_pre (Type const&)
      {
      }

      void ImplementationRequirement::
      property_next (Type&)
      {
      }

      void ImplementationRequirement::
      property_next (Type const&)
      {
      }

      void ImplementationRequirement::
      property_post (Type&)
      {
      }

      void ImplementationRequirement::
      property_post (Type const&)
      {
      }

      void ImplementationRequirement::
      property_none (Type&)
      {
      }

      void ImplementationRequirement::
      property_none (Type const&)
      {
      }

      void ImplementationRequirement::
      post (Type&)
      {
      }

      void ImplementationRequirement::
      post (Type const&)
      {
      }

      // ComponentPackageReference
      //
      //

      void ComponentPackageReference::
      traverse (Type& o)
      {
        pre (o);
        if (o.requiredUUID_p ()) requiredUUID (o);
        else requiredUUID_none (o);
        if (o.requiredName_p ()) requiredName (o);
        else requiredName_none (o);
        requiredType (o);
        post (o);
      }

      void ComponentPackageReference::
      traverse (Type const& o)
      {
        pre (o);
        if (o.requiredUUID_p ()) requiredUUID (o);
        else requiredUUID_none (o);
        if (o.requiredName_p ()) requiredName (o);
        else requiredName_none (o);
        requiredType (o);
        post (o);
      }

      void ComponentPackageReference::
      pre (Type&)
      {
      }

      void ComponentPackageReference::
      pre (Type const&)
      {
      }

      void ComponentPackageReference::
      requiredUUID (Type& o)
      {
        dispatch (o.requiredUUID ());
      }

      void ComponentPackageReference::
      requiredUUID (Type const& o)
      {
        dispatch (o.requiredUUID ());
      }

      void ComponentPackageReference::
      requiredUUID_none (Type&)
      {
      }

      void ComponentPackageReference::
      requiredUUID_none (Type const&)
      {
      }

      void ComponentPackageReference::
      requiredName (Type& o)
      {
        dispatch (o.requiredName ());
      }

      void ComponentPackageReference::
      requiredName (Type const& o)
      {
        dispatch (o.requiredName ());
      }

      void ComponentPackageReference::
      requiredName_none (Type&)
      {
      }

      void ComponentPackageReference::
      requiredName_none (Type const&)
      {
      }

      void ComponentPackageReference::
      requiredType (Type& o)
      {
        dispatch (o.requiredType ());
      }

      void ComponentPackageReference::
      requiredType (Type const& o)
      {
        dispatch (o.requiredType ());
      }

      void ComponentPackageReference::
      post (Type&)
      {
      }

      void ComponentPackageReference::
      post (Type const&)
      {
      }

      // SubcomponentPortEndpoint
      //
      //

      void SubcomponentPortEndpoint::
      traverse (Type& o)
      {
        pre (o);
        portName (o);
        instance (o);
        post (o);
      }

      void SubcomponentPortEndpoint::
      traverse (Type const& o)
      {
        pre (o);
        portName (o);
        instance (o);
        post (o);
      }

      void SubcomponentPortEndpoint::
      pre (Type&)
      {
      }

      void SubcomponentPortEndpoint::
      pre (Type const&)
      {
      }

      void SubcomponentPortEndpoint::
      portName (Type& o)
      {
        dispatch (o.portName ());
      }

      void SubcomponentPortEndpoint::
      portName (Type const& o)
      {
        dispatch (o.portName ());
      }

      void SubcomponentPortEndpoint::
      instance (Type& o)
      {
        dispatch (o.instance ());
      }

      void SubcomponentPortEndpoint::
      instance (Type const& o)
      {
        dispatch (o.instance ());
      }

      void SubcomponentPortEndpoint::
      post (Type&)
      {
      }

      void SubcomponentPortEndpoint::
      post (Type const&)
      {
      }

      // AssemblyConnectionDescription
      //
      //

      void AssemblyConnectionDescription::
      traverse (Type& o)
      {
        pre (o);
        name (o);
        deployRequirement (o);
        internalEndpoint (o);
        externalEndpoint (o);
        externalReference (o);
        post (o);
      }

      void AssemblyConnectionDescription::
      traverse (Type const& o)
      {
        pre (o);
        name (o);
        deployRequirement (o);
        internalEndpoint (o);
        externalEndpoint (o);
        externalReference (o);
        post (o);
      }

      void AssemblyConnectionDescription::
      pre (Type&)
      {
      }

      void AssemblyConnectionDescription::
      pre (Type const&)
      {
      }

      void AssemblyConnectionDescription::
      name (Type& o)
      {
        dispatch (o.name ());
      }

      void AssemblyConnectionDescription::
      name (Type const& o)
      {
        dispatch (o.name ());
      }

      void AssemblyConnectionDescription::
      deployRequirement (Type& o)
      {
        // VC6 anathema strikes again
        //
        AssemblyConnectionDescription::Type::deployRequirement_iterator b (o.begin_deployRequirement()), e (o.end_deployRequirement());

        if (b != e)
        {
          deployRequirement_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) deployRequirement_next (o);
          }

          deployRequirement_post (o);
        }

        else deployRequirement_none (o);
      }

      void AssemblyConnectionDescription::
      deployRequirement (Type const& o)
      {
        // VC6 anathema strikes again
        //
        AssemblyConnectionDescription::Type::deployRequirement_const_iterator b (o.begin_deployRequirement()), e (o.end_deployRequirement());

        if (b != e)
        {
          deployRequirement_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) deployRequirement_next (o);
          }

          deployRequirement_post (o);
        }

        else deployRequirement_none (o);
      }

      void AssemblyConnectionDescription::
      deployRequirement_pre (Type&)
      {
      }

      void AssemblyConnectionDescription::
      deployRequirement_pre (Type const&)
      {
      }

      void AssemblyConnectionDescription::
      deployRequirement_next (Type&)
      {
      }

      void AssemblyConnectionDescription::
      deployRequirement_next (Type const&)
      {
      }

      void AssemblyConnectionDescription::
      deployRequirement_post (Type&)
      {
      }

      void AssemblyConnectionDescription::
      deployRequirement_post (Type const&)
      {
      }

      void AssemblyConnectionDescription::
      deployRequirement_none (Type&)
      {
      }

      void AssemblyConnectionDescription::
      deployRequirement_none (Type const&)
      {
      }

      void AssemblyConnectionDescription::
      internalEndpoint (Type& o)
      {
        // VC6 anathema strikes again
        //
        AssemblyConnectionDescription::Type::internalEndpoint_iterator b (o.begin_internalEndpoint()), e (o.end_internalEndpoint());

        if (b != e)
        {
          internalEndpoint_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) internalEndpoint_next (o);
          }

          internalEndpoint_post (o);
        }

        else internalEndpoint_none (o);
      }

      void AssemblyConnectionDescription::
      internalEndpoint (Type const& o)
      {
        // VC6 anathema strikes again
        //
        AssemblyConnectionDescription::Type::internalEndpoint_const_iterator b (o.begin_internalEndpoint()), e (o.end_internalEndpoint());

        if (b != e)
        {
          internalEndpoint_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) internalEndpoint_next (o);
          }

          internalEndpoint_post (o);
        }

        else internalEndpoint_none (o);
      }

      void AssemblyConnectionDescription::
      internalEndpoint_pre (Type&)
      {
      }

      void AssemblyConnectionDescription::
      internalEndpoint_pre (Type const&)
      {
      }

      void AssemblyConnectionDescription::
      internalEndpoint_next (Type&)
      {
      }

      void AssemblyConnectionDescription::
      internalEndpoint_next (Type const&)
      {
      }

      void AssemblyConnectionDescription::
      internalEndpoint_post (Type&)
      {
      }

      void AssemblyConnectionDescription::
      internalEndpoint_post (Type const&)
      {
      }

      void AssemblyConnectionDescription::
      internalEndpoint_none (Type&)
      {
      }

      void AssemblyConnectionDescription::
      internalEndpoint_none (Type const&)
      {
      }

      void AssemblyConnectionDescription::
      externalEndpoint (Type& o)
      {
        // VC6 anathema strikes again
        //
        AssemblyConnectionDescription::Type::externalEndpoint_iterator b (o.begin_externalEndpoint()), e (o.end_externalEndpoint());

        if (b != e)
        {
          externalEndpoint_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) externalEndpoint_next (o);
          }

          externalEndpoint_post (o);
        }

        else externalEndpoint_none (o);
      }

      void AssemblyConnectionDescription::
      externalEndpoint (Type const& o)
      {
        // VC6 anathema strikes again
        //
        AssemblyConnectionDescription::Type::externalEndpoint_const_iterator b (o.begin_externalEndpoint()), e (o.end_externalEndpoint());

        if (b != e)
        {
          externalEndpoint_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) externalEndpoint_next (o);
          }

          externalEndpoint_post (o);
        }

        else externalEndpoint_none (o);
      }

      void AssemblyConnectionDescription::
      externalEndpoint_pre (Type&)
      {
      }

      void AssemblyConnectionDescription::
      externalEndpoint_pre (Type const&)
      {
      }

      void AssemblyConnectionDescription::
      externalEndpoint_next (Type&)
      {
      }

      void AssemblyConnectionDescription::
      externalEndpoint_next (Type const&)
      {
      }

      void AssemblyConnectionDescription::
      externalEndpoint_post (Type&)
      {
      }

      void AssemblyConnectionDescription::
      externalEndpoint_post (Type const&)
      {
      }

      void AssemblyConnectionDescription::
      externalEndpoint_none (Type&)
      {
      }

      void AssemblyConnectionDescription::
      externalEndpoint_none (Type const&)
      {
      }

      void AssemblyConnectionDescription::
      externalReference (Type& o)
      {
        // VC6 anathema strikes again
        //
        AssemblyConnectionDescription::Type::externalReference_iterator b (o.begin_externalReference()), e (o.end_externalReference());

        if (b != e)
        {
          externalReference_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) externalReference_next (o);
          }

          externalReference_post (o);
        }

        else externalReference_none (o);
      }

      void AssemblyConnectionDescription::
      externalReference (Type const& o)
      {
        // VC6 anathema strikes again
        //
        AssemblyConnectionDescription::Type::externalReference_const_iterator b (o.begin_externalReference()), e (o.end_externalReference());

        if (b != e)
        {
          externalReference_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) externalReference_next (o);
          }

          externalReference_post (o);
        }

        else externalReference_none (o);
      }

      void AssemblyConnectionDescription::
      externalReference_pre (Type&)
      {
      }

      void AssemblyConnectionDescription::
      externalReference_pre (Type const&)
      {
      }

      void AssemblyConnectionDescription::
      externalReference_next (Type&)
      {
      }

      void AssemblyConnectionDescription::
      externalReference_next (Type const&)
      {
      }

      void AssemblyConnectionDescription::
      externalReference_post (Type&)
      {
      }

      void AssemblyConnectionDescription::
      externalReference_post (Type const&)
      {
      }

      void AssemblyConnectionDescription::
      externalReference_none (Type&)
      {
      }

      void AssemblyConnectionDescription::
      externalReference_none (Type const&)
      {
      }

      void AssemblyConnectionDescription::
      post (Type&)
      {
      }

      void AssemblyConnectionDescription::
      post (Type const&)
      {
      }
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Writer
    {
      // TCKind
      //
      //

      TCKind::
      TCKind (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      TCKind::
      TCKind ()
      {
      }

      void TCKind::
      traverse (Type const& o)
      {
        ::std::basic_string< ACE_TCHAR > s;

        if (o == ::CIAO::Config_Handlers::TCKind::tk_null) s = "tk_null";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_void) s = "tk_void";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_short) s = "tk_short";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_long) s = "tk_long";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_ushort) s = "tk_ushort";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_ulong) s = "tk_ulong";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_float) s = "tk_float";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_double) s = "tk_double";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_boolean) s = "tk_boolean";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_char) s = "tk_char";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_octet) s = "tk_octet";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_any) s = "tk_any";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_TypeCode) s = "tk_TypeCode";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_Principal) s = "tk_Principal";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_objref) s = "tk_objref";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_struct) s = "tk_struct";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_union) s = "tk_union";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_enum) s = "tk_enum";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_string) s = "tk_string";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_sequence) s = "tk_sequence";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_array) s = "tk_array";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_alias) s = "tk_alias";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_except) s = "tk_except";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_longlong) s = "tk_longlong";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_ulonglong) s = "tk_ulonglong";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_longdouble) s = "tk_longdouble";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_wchar) s = "tk_wchar";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_wstring) s = "tk_wstring";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_wfixed) s = "tk_wfixed";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_value) s = "tk_value";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_value_box) s = "tk_value_box";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_native) s = "tk_native";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_abstract_interface) s = "tk_abstract_interface";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_local_interface) s = "tk_local_interface";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_component) s = "tk_component";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_home) s = "tk_home";
        else if (o == ::CIAO::Config_Handlers::TCKind::tk_event) s = "tk_event";
        else 
        {
        }

        if (::XSCRT::XML::Attribute< ACE_TCHAR >* a = attr_ ())
        {
          a->value (s);
        }

        else
        {
          top_().value (s);
        }
      }

      // DataType
      //
      //

      DataType::
      DataType (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      DataType::
      DataType ()
      {
      }

      void DataType::
      traverse (Type const& o)
      {
        Traversal::DataType::traverse (o);
      }

      void DataType::
      kind (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("kind", top_ ()));
        Traversal::DataType::kind (o);
        pop_ ();
      }

      void DataType::
      enum_ (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("enum", top_ ()));
        Traversal::DataType::enum_ (o);
        pop_ ();
      }

      // DataValue
      //
      //

      DataValue::
      DataValue (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      DataValue::
      DataValue ()
      {
      }

      void DataValue::
      traverse (Type const& o)
      {
        Traversal::DataValue::traverse (o);
      }

      void DataValue::
      short_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("short", top_ ()));
      }

      void DataValue::
      short_next (Type const& o)
      {
        short_post (o);
        short_pre (o);
      }

      void DataValue::
      short_post (Type const&)
      {
        pop_ ();
      }

      void DataValue::
      long_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("long", top_ ()));
      }

      void DataValue::
      long_next (Type const& o)
      {
        long_post (o);
        long_pre (o);
      }

      void DataValue::
      long_post (Type const&)
      {
        pop_ ();
      }

      void DataValue::
      ushort_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("ushort", top_ ()));
      }

      void DataValue::
      ushort_next (Type const& o)
      {
        ushort_post (o);
        ushort_pre (o);
      }

      void DataValue::
      ushort_post (Type const&)
      {
        pop_ ();
      }

      void DataValue::
      ulong_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("ulong", top_ ()));
      }

      void DataValue::
      ulong_next (Type const& o)
      {
        ulong_post (o);
        ulong_pre (o);
      }

      void DataValue::
      ulong_post (Type const&)
      {
        pop_ ();
      }

      void DataValue::
      float_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("float", top_ ()));
      }

      void DataValue::
      float_next (Type const& o)
      {
        float_post (o);
        float_pre (o);
      }

      void DataValue::
      float_post (Type const&)
      {
        pop_ ();
      }

      void DataValue::
      double_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("double", top_ ()));
      }

      void DataValue::
      double_next (Type const& o)
      {
        double_post (o);
        double_pre (o);
      }

      void DataValue::
      double_post (Type const&)
      {
        pop_ ();
      }

      void DataValue::
      boolean_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("boolean", top_ ()));
      }

      void DataValue::
      boolean_next (Type const& o)
      {
        boolean_post (o);
        boolean_pre (o);
      }

      void DataValue::
      boolean_post (Type const&)
      {
        pop_ ();
      }

      void DataValue::
      octet_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("octet", top_ ()));
      }

      void DataValue::
      octet_next (Type const& o)
      {
        octet_post (o);
        octet_pre (o);
      }

      void DataValue::
      octet_post (Type const&)
      {
        pop_ ();
      }

      void DataValue::
      enum_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("enum", top_ ()));
      }

      void DataValue::
      enum_next (Type const& o)
      {
        enum_post (o);
        enum_pre (o);
      }

      void DataValue::
      enum_post (Type const&)
      {
        pop_ ();
      }

      void DataValue::
      string_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("string", top_ ()));
      }

      void DataValue::
      string_next (Type const& o)
      {
        string_post (o);
        string_pre (o);
      }

      void DataValue::
      string_post (Type const&)
      {
        pop_ ();
      }

      void DataValue::
      longlong_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("longlong", top_ ()));
      }

      void DataValue::
      longlong_next (Type const& o)
      {
        longlong_post (o);
        longlong_pre (o);
      }

      void DataValue::
      longlong_post (Type const&)
      {
        pop_ ();
      }

      void DataValue::
      ulonglong_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("ulonglong", top_ ()));
      }

      void DataValue::
      ulonglong_next (Type const& o)
      {
        ulonglong_post (o);
        ulonglong_pre (o);
      }

      void DataValue::
      ulonglong_post (Type const&)
      {
        pop_ ();
      }

      void DataValue::
      longdouble_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("longdouble", top_ ()));
      }

      void DataValue::
      longdouble_next (Type const& o)
      {
        longdouble_post (o);
        longdouble_pre (o);
      }

      void DataValue::
      longdouble_post (Type const&)
      {
        pop_ ();
      }

      // EnumType
      //
      //

      EnumType::
      EnumType (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      EnumType::
      EnumType ()
      {
      }

      void EnumType::
      traverse (Type const& o)
      {
        Traversal::EnumType::traverse (o);
      }

      void EnumType::
      name (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("name", top_ ()));
        Traversal::EnumType::name (o);
        pop_ ();
      }

      void EnumType::
      typeId (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("typeId", top_ ()));
        Traversal::EnumType::typeId (o);
        pop_ ();
      }

      void EnumType::
      member_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("member", top_ ()));
      }

      void EnumType::
      member_next (Type const& o)
      {
        member_post (o);
        member_pre (o);
      }

      void EnumType::
      member_post (Type const&)
      {
        pop_ ();
      }

      // Any
      //
      //

      Any::
      Any (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      Any::
      Any ()
      {
      }

      void Any::
      traverse (Type const& o)
      {
        Traversal::Any::traverse (o);
      }

      void Any::
      type (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("type", top_ ()));
        Traversal::Any::type (o);
        pop_ ();
      }

      void Any::
      value (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("value", top_ ()));
        Traversal::Any::value (o);
        pop_ ();
      }

      // Property
      //
      //

      Property::
      Property (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      Property::
      Property ()
      {
      }

      void Property::
      traverse (Type const& o)
      {
        Traversal::Property::traverse (o);
      }

      void Property::
      name (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("name", top_ ()));
        Traversal::Property::name (o);
        pop_ ();
      }

      void Property::
      value (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("value", top_ ()));
        Traversal::Property::value (o);
        pop_ ();
      }

      // SatisfierPropertyKind
      //
      //

      SatisfierPropertyKind::
      SatisfierPropertyKind (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      SatisfierPropertyKind::
      SatisfierPropertyKind ()
      {
      }

      void SatisfierPropertyKind::
      traverse (Type const& o)
      {
        ::std::basic_string< ACE_TCHAR > s;

        if (o == ::CIAO::Config_Handlers::SatisfierPropertyKind::Quantity) s = "Quantity";
        else if (o == ::CIAO::Config_Handlers::SatisfierPropertyKind::Capacity) s = "Capacity";
        else if (o == ::CIAO::Config_Handlers::SatisfierPropertyKind::Minimum) s = "Minimum";
        else if (o == ::CIAO::Config_Handlers::SatisfierPropertyKind::Maximum) s = "Maximum";
        else if (o == ::CIAO::Config_Handlers::SatisfierPropertyKind::Attribute) s = "Attribute";
        else if (o == ::CIAO::Config_Handlers::SatisfierPropertyKind::Selection) s = "Selection";
        else 
        {
        }

        if (::XSCRT::XML::Attribute< ACE_TCHAR >* a = attr_ ())
        {
          a->value (s);
        }

        else
        {
          top_().value (s);
        }
      }

      // SatisfierProperty
      //
      //

      SatisfierProperty::
      SatisfierProperty (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      SatisfierProperty::
      SatisfierProperty ()
      {
      }

      void SatisfierProperty::
      traverse (Type const& o)
      {
        Traversal::SatisfierProperty::traverse (o);
      }

      void SatisfierProperty::
      name (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("name", top_ ()));
        Traversal::SatisfierProperty::name (o);
        pop_ ();
      }

      void SatisfierProperty::
      kind (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("kind", top_ ()));
        Traversal::SatisfierProperty::kind (o);
        pop_ ();
      }

      void SatisfierProperty::
      dynamic (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("dynamic", top_ ()));
        Traversal::SatisfierProperty::dynamic (o);
        pop_ ();
      }

      void SatisfierProperty::
      value (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("value", top_ ()));
        Traversal::SatisfierProperty::value (o);
        pop_ ();
      }

      // Resource
      //
      //

      Resource::
      Resource (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      Resource::
      Resource ()
      {
      }

      void Resource::
      traverse (Type const& o)
      {
        Traversal::Resource::traverse (o);
      }

      void Resource::
      name (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("name", top_ ()));
        Traversal::Resource::name (o);
        pop_ ();
      }

      void Resource::
      resourceType_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("resourceType", top_ ()));
      }

      void Resource::
      resourceType_next (Type const& o)
      {
        resourceType_post (o);
        resourceType_pre (o);
      }

      void Resource::
      resourceType_post (Type const&)
      {
        pop_ ();
      }

      void Resource::
      property_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("property", top_ ()));
      }

      void Resource::
      property_next (Type const& o)
      {
        property_post (o);
        property_pre (o);
      }

      void Resource::
      property_post (Type const&)
      {
        pop_ ();
      }

      // Requirement
      //
      //

      Requirement::
      Requirement (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      Requirement::
      Requirement ()
      {
      }

      void Requirement::
      traverse (Type const& o)
      {
        Traversal::Requirement::traverse (o);
      }

      void Requirement::
      resourceType (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("resourceType", top_ ()));
        Traversal::Requirement::resourceType (o);
        pop_ ();
      }

      void Requirement::
      name (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("name", top_ ()));
        Traversal::Requirement::name (o);
        pop_ ();
      }

      void Requirement::
      property_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("property", top_ ()));
      }

      void Requirement::
      property_next (Type const& o)
      {
        property_post (o);
        property_pre (o);
      }

      void Requirement::
      property_post (Type const&)
      {
        pop_ ();
      }

      // ResourceDeploymentDescription
      //
      //

      ResourceDeploymentDescription::
      ResourceDeploymentDescription (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      ResourceDeploymentDescription::
      ResourceDeploymentDescription ()
      {
      }

      void ResourceDeploymentDescription::
      traverse (Type const& o)
      {
        Traversal::ResourceDeploymentDescription::traverse (o);
      }

      void ResourceDeploymentDescription::
      requirementName (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("requirementName", top_ ()));
        Traversal::ResourceDeploymentDescription::requirementName (o);
        pop_ ();
      }

      void ResourceDeploymentDescription::
      resourceName (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("resourceName", top_ ()));
        Traversal::ResourceDeploymentDescription::resourceName (o);
        pop_ ();
      }

      void ResourceDeploymentDescription::
      property_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("property", top_ ()));
      }

      void ResourceDeploymentDescription::
      property_next (Type const& o)
      {
        property_post (o);
        property_pre (o);
      }

      void ResourceDeploymentDescription::
      property_post (Type const&)
      {
        pop_ ();
      }

      // ArtifactDeploymentDescription
      //
      //

      ArtifactDeploymentDescription::
      ArtifactDeploymentDescription (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      ArtifactDeploymentDescription::
      ArtifactDeploymentDescription ()
      {
      }

      void ArtifactDeploymentDescription::
      traverse (Type const& o)
      {
        Traversal::ArtifactDeploymentDescription::traverse (o);
      }

      void ArtifactDeploymentDescription::
      name (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("name", top_ ()));
        Traversal::ArtifactDeploymentDescription::name (o);
        pop_ ();
      }

      void ArtifactDeploymentDescription::
      source_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("source", top_ ()));
      }

      void ArtifactDeploymentDescription::
      source_next (Type const& o)
      {
        source_post (o);
        source_pre (o);
      }

      void ArtifactDeploymentDescription::
      source_post (Type const&)
      {
        pop_ ();
      }

      void ArtifactDeploymentDescription::
      node (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("node", top_ ()));
        Traversal::ArtifactDeploymentDescription::node (o);
        pop_ ();
      }

      void ArtifactDeploymentDescription::
      location_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("location", top_ ()));
      }

      void ArtifactDeploymentDescription::
      location_next (Type const& o)
      {
        location_post (o);
        location_pre (o);
      }

      void ArtifactDeploymentDescription::
      location_post (Type const&)
      {
        pop_ ();
      }

      void ArtifactDeploymentDescription::
      execParameter_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("execParameter", top_ ()));
      }

      void ArtifactDeploymentDescription::
      execParameter_next (Type const& o)
      {
        execParameter_post (o);
        execParameter_pre (o);
      }

      void ArtifactDeploymentDescription::
      execParameter_post (Type const&)
      {
        pop_ ();
      }

      void ArtifactDeploymentDescription::
      deployRequirement_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("deployRequirement", top_ ()));
      }

      void ArtifactDeploymentDescription::
      deployRequirement_next (Type const& o)
      {
        deployRequirement_post (o);
        deployRequirement_pre (o);
      }

      void ArtifactDeploymentDescription::
      deployRequirement_post (Type const&)
      {
        pop_ ();
      }

      void ArtifactDeploymentDescription::
      deployedResource_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("deployedResource", top_ ()));
      }

      void ArtifactDeploymentDescription::
      deployedResource_next (Type const& o)
      {
        deployedResource_post (o);
        deployedResource_pre (o);
      }

      void ArtifactDeploymentDescription::
      deployedResource_post (Type const&)
      {
        pop_ ();
      }

      void ArtifactDeploymentDescription::
      id (Type const& o)
      {
        ::XSCRT::XML::Attribute< ACE_TCHAR > a ("id", "", top_ ());
        attr_ (&a);
        Traversal::ArtifactDeploymentDescription::id (o);
        attr_ (0);
      }

      // MonolithicDeploymentDescription
      //
      //

      MonolithicDeploymentDescription::
      MonolithicDeploymentDescription (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      MonolithicDeploymentDescription::
      MonolithicDeploymentDescription ()
      {
      }

      void MonolithicDeploymentDescription::
      traverse (Type const& o)
      {
        Traversal::MonolithicDeploymentDescription::traverse (o);
      }

      void MonolithicDeploymentDescription::
      name (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("name", top_ ()));
        Traversal::MonolithicDeploymentDescription::name (o);
        pop_ ();
      }

      void MonolithicDeploymentDescription::
      source_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("source", top_ ()));
      }

      void MonolithicDeploymentDescription::
      source_next (Type const& o)
      {
        source_post (o);
        source_pre (o);
      }

      void MonolithicDeploymentDescription::
      source_post (Type const&)
      {
        pop_ ();
      }

      void MonolithicDeploymentDescription::
      artifact_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("artifact", top_ ()));
      }

      void MonolithicDeploymentDescription::
      artifact_next (Type const& o)
      {
        artifact_post (o);
        artifact_pre (o);
      }

      void MonolithicDeploymentDescription::
      artifact_post (Type const&)
      {
        pop_ ();
      }

      void MonolithicDeploymentDescription::
      execParameter_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("execParameter", top_ ()));
      }

      void MonolithicDeploymentDescription::
      execParameter_next (Type const& o)
      {
        execParameter_post (o);
        execParameter_pre (o);
      }

      void MonolithicDeploymentDescription::
      execParameter_post (Type const&)
      {
        pop_ ();
      }

      void MonolithicDeploymentDescription::
      deployRequirement_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("deployRequirement", top_ ()));
      }

      void MonolithicDeploymentDescription::
      deployRequirement_next (Type const& o)
      {
        deployRequirement_post (o);
        deployRequirement_pre (o);
      }

      void MonolithicDeploymentDescription::
      deployRequirement_post (Type const&)
      {
        pop_ ();
      }

      void MonolithicDeploymentDescription::
      id (Type const& o)
      {
        ::XSCRT::XML::Attribute< ACE_TCHAR > a ("id", "", top_ ());
        attr_ (&a);
        Traversal::MonolithicDeploymentDescription::id (o);
        attr_ (0);
      }

      // ResourceUsageKind
      //
      //

      ResourceUsageKind::
      ResourceUsageKind (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      ResourceUsageKind::
      ResourceUsageKind ()
      {
      }

      void ResourceUsageKind::
      traverse (Type const& o)
      {
        ::std::basic_string< ACE_TCHAR > s;

        if (o == ::CIAO::Config_Handlers::ResourceUsageKind::None) s = "None";
        else if (o == ::CIAO::Config_Handlers::ResourceUsageKind::InstanceUsesResource) s = "InstanceUsesResource";
        else if (o == ::CIAO::Config_Handlers::ResourceUsageKind::ResourceUsesInstance) s = "ResourceUsesInstance";
        else if (o == ::CIAO::Config_Handlers::ResourceUsageKind::PortUsesResource) s = "PortUsesResource";
        else if (o == ::CIAO::Config_Handlers::ResourceUsageKind::ResourceUsesPort) s = "ResourceUsesPort";
        else 
        {
        }

        if (::XSCRT::XML::Attribute< ACE_TCHAR >* a = attr_ ())
        {
          a->value (s);
        }

        else
        {
          top_().value (s);
        }
      }

      // InstanceResourceDeploymentDescription
      //
      //

      InstanceResourceDeploymentDescription::
      InstanceResourceDeploymentDescription (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      InstanceResourceDeploymentDescription::
      InstanceResourceDeploymentDescription ()
      {
      }

      void InstanceResourceDeploymentDescription::
      traverse (Type const& o)
      {
        Traversal::InstanceResourceDeploymentDescription::traverse (o);
      }

      void InstanceResourceDeploymentDescription::
      resourceUsage (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("resourceUsage", top_ ()));
        Traversal::InstanceResourceDeploymentDescription::resourceUsage (o);
        pop_ ();
      }

      void InstanceResourceDeploymentDescription::
      requirementName (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("requirementName", top_ ()));
        Traversal::InstanceResourceDeploymentDescription::requirementName (o);
        pop_ ();
      }

      void InstanceResourceDeploymentDescription::
      resourceName (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("resourceName", top_ ()));
        Traversal::InstanceResourceDeploymentDescription::resourceName (o);
        pop_ ();
      }

      void InstanceResourceDeploymentDescription::
      property_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("property", top_ ()));
      }

      void InstanceResourceDeploymentDescription::
      property_next (Type const& o)
      {
        property_post (o);
        property_pre (o);
      }

      void InstanceResourceDeploymentDescription::
      property_post (Type const&)
      {
        pop_ ();
      }

      // InstanceDeploymentDescription
      //
      //

      InstanceDeploymentDescription::
      InstanceDeploymentDescription (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      InstanceDeploymentDescription::
      InstanceDeploymentDescription ()
      {
      }

      void InstanceDeploymentDescription::
      traverse (Type const& o)
      {
        Traversal::InstanceDeploymentDescription::traverse (o);
      }

      void InstanceDeploymentDescription::
      name (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("name", top_ ()));
        Traversal::InstanceDeploymentDescription::name (o);
        pop_ ();
      }

      void InstanceDeploymentDescription::
      node (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("node", top_ ()));
        Traversal::InstanceDeploymentDescription::node (o);
        pop_ ();
      }

      void InstanceDeploymentDescription::
      source (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("source", top_ ()));
        Traversal::InstanceDeploymentDescription::source (o);
        pop_ ();
      }

      void InstanceDeploymentDescription::
      implementation (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("implementation", top_ ()));
        Traversal::InstanceDeploymentDescription::implementation (o);
        pop_ ();
      }

      void InstanceDeploymentDescription::
      configProperty_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("configProperty", top_ ()));
      }

      void InstanceDeploymentDescription::
      configProperty_next (Type const& o)
      {
        configProperty_post (o);
        configProperty_pre (o);
      }

      void InstanceDeploymentDescription::
      configProperty_post (Type const&)
      {
        pop_ ();
      }

      void InstanceDeploymentDescription::
      deployedResource_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("deployedResource", top_ ()));
      }

      void InstanceDeploymentDescription::
      deployedResource_next (Type const& o)
      {
        deployedResource_post (o);
        deployedResource_pre (o);
      }

      void InstanceDeploymentDescription::
      deployedResource_post (Type const&)
      {
        pop_ ();
      }

      void InstanceDeploymentDescription::
      deployedSharedResource (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("deployedSharedResource", top_ ()));
        Traversal::InstanceDeploymentDescription::deployedSharedResource (o);
        pop_ ();
      }

      void InstanceDeploymentDescription::
      id (Type const& o)
      {
        ::XSCRT::XML::Attribute< ACE_TCHAR > a ("id", "", top_ ());
        attr_ (&a);
        Traversal::InstanceDeploymentDescription::id (o);
        attr_ (0);
      }

      // CCMComponentPortKind
      //
      //

      CCMComponentPortKind::
      CCMComponentPortKind (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      CCMComponentPortKind::
      CCMComponentPortKind ()
      {
      }

      void CCMComponentPortKind::
      traverse (Type const& o)
      {
        ::std::basic_string< ACE_TCHAR > s;

        if (o == ::CIAO::Config_Handlers::CCMComponentPortKind::Facet) s = "Facet";
        else if (o == ::CIAO::Config_Handlers::CCMComponentPortKind::SimplexReceptacle) s = "SimplexReceptacle";
        else if (o == ::CIAO::Config_Handlers::CCMComponentPortKind::MultiplexReceptacle) s = "MultiplexReceptacle";
        else if (o == ::CIAO::Config_Handlers::CCMComponentPortKind::EventEmitter) s = "EventEmitter";
        else if (o == ::CIAO::Config_Handlers::CCMComponentPortKind::EventPublisher) s = "EventPublisher";
        else if (o == ::CIAO::Config_Handlers::CCMComponentPortKind::EventConsumer) s = "EventConsumer";
        else 
        {
        }

        if (::XSCRT::XML::Attribute< ACE_TCHAR >* a = attr_ ())
        {
          a->value (s);
        }

        else
        {
          top_().value (s);
        }
      }

      // ComponentPortDescription
      //
      //

      ComponentPortDescription::
      ComponentPortDescription (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      ComponentPortDescription::
      ComponentPortDescription ()
      {
      }

      void ComponentPortDescription::
      traverse (Type const& o)
      {
        Traversal::ComponentPortDescription::traverse (o);
      }

      void ComponentPortDescription::
      name (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("name", top_ ()));
        Traversal::ComponentPortDescription::name (o);
        pop_ ();
      }

      void ComponentPortDescription::
      specificType (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("specificType", top_ ()));
        Traversal::ComponentPortDescription::specificType (o);
        pop_ ();
      }

      void ComponentPortDescription::
      supportedType_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("supportedType", top_ ()));
      }

      void ComponentPortDescription::
      supportedType_next (Type const& o)
      {
        supportedType_post (o);
        supportedType_pre (o);
      }

      void ComponentPortDescription::
      supportedType_post (Type const&)
      {
        pop_ ();
      }

      void ComponentPortDescription::
      provider (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("provider", top_ ()));
        Traversal::ComponentPortDescription::provider (o);
        pop_ ();
      }

      void ComponentPortDescription::
      exclusiveProvider (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("exclusiveProvider", top_ ()));
        Traversal::ComponentPortDescription::exclusiveProvider (o);
        pop_ ();
      }

      void ComponentPortDescription::
      exclusiveUser (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("exclusiveUser", top_ ()));
        Traversal::ComponentPortDescription::exclusiveUser (o);
        pop_ ();
      }

      void ComponentPortDescription::
      optional (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("optional", top_ ()));
        Traversal::ComponentPortDescription::optional (o);
        pop_ ();
      }

      void ComponentPortDescription::
      kind (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("kind", top_ ()));
        Traversal::ComponentPortDescription::kind (o);
        pop_ ();
      }

      // ComponentPropertyDescription
      //
      //

      ComponentPropertyDescription::
      ComponentPropertyDescription (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      ComponentPropertyDescription::
      ComponentPropertyDescription ()
      {
      }

      void ComponentPropertyDescription::
      traverse (Type const& o)
      {
        Traversal::ComponentPropertyDescription::traverse (o);
      }

      void ComponentPropertyDescription::
      name (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("name", top_ ()));
        Traversal::ComponentPropertyDescription::name (o);
        pop_ ();
      }

      void ComponentPropertyDescription::
      type (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("type", top_ ()));
        Traversal::ComponentPropertyDescription::type (o);
        pop_ ();
      }

      // ComponentExternalPortEndpoint
      //
      //

      ComponentExternalPortEndpoint::
      ComponentExternalPortEndpoint (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      ComponentExternalPortEndpoint::
      ComponentExternalPortEndpoint ()
      {
      }

      void ComponentExternalPortEndpoint::
      traverse (Type const& o)
      {
        Traversal::ComponentExternalPortEndpoint::traverse (o);
      }

      void ComponentExternalPortEndpoint::
      portName (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("portName", top_ ()));
        Traversal::ComponentExternalPortEndpoint::portName (o);
        pop_ ();
      }

      // PlanSubcomponentPortEndpoint
      //
      //

      PlanSubcomponentPortEndpoint::
      PlanSubcomponentPortEndpoint (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      PlanSubcomponentPortEndpoint::
      PlanSubcomponentPortEndpoint ()
      {
      }

      void PlanSubcomponentPortEndpoint::
      traverse (Type const& o)
      {
        Traversal::PlanSubcomponentPortEndpoint::traverse (o);
      }

      void PlanSubcomponentPortEndpoint::
      portName (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("portName", top_ ()));
        Traversal::PlanSubcomponentPortEndpoint::portName (o);
        pop_ ();
      }

      void PlanSubcomponentPortEndpoint::
      provider (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("provider", top_ ()));
        Traversal::PlanSubcomponentPortEndpoint::provider (o);
        pop_ ();
      }

      void PlanSubcomponentPortEndpoint::
      kind (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("kind", top_ ()));
        Traversal::PlanSubcomponentPortEndpoint::kind (o);
        pop_ ();
      }

      void PlanSubcomponentPortEndpoint::
      instance (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("instance", top_ ()));
        Traversal::PlanSubcomponentPortEndpoint::instance (o);
        pop_ ();
      }

      // ExternalReferenceEndpoint
      //
      //

      ExternalReferenceEndpoint::
      ExternalReferenceEndpoint (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      ExternalReferenceEndpoint::
      ExternalReferenceEndpoint ()
      {
      }

      void ExternalReferenceEndpoint::
      traverse (Type const& o)
      {
        Traversal::ExternalReferenceEndpoint::traverse (o);
      }

      void ExternalReferenceEndpoint::
      location (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("location", top_ ()));
        Traversal::ExternalReferenceEndpoint::location (o);
        pop_ ();
      }

      // ConnectionResourceDeploymentDescription
      //
      //

      ConnectionResourceDeploymentDescription::
      ConnectionResourceDeploymentDescription (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      ConnectionResourceDeploymentDescription::
      ConnectionResourceDeploymentDescription ()
      {
      }

      void ConnectionResourceDeploymentDescription::
      traverse (Type const& o)
      {
        Traversal::ConnectionResourceDeploymentDescription::traverse (o);
      }

      void ConnectionResourceDeploymentDescription::
      targetName (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("targetName", top_ ()));
        Traversal::ConnectionResourceDeploymentDescription::targetName (o);
        pop_ ();
      }

      void ConnectionResourceDeploymentDescription::
      requirementName (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("requirementName", top_ ()));
        Traversal::ConnectionResourceDeploymentDescription::requirementName (o);
        pop_ ();
      }

      void ConnectionResourceDeploymentDescription::
      resourceName (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("resourceName", top_ ()));
        Traversal::ConnectionResourceDeploymentDescription::resourceName (o);
        pop_ ();
      }

      void ConnectionResourceDeploymentDescription::
      property_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("property", top_ ()));
      }

      void ConnectionResourceDeploymentDescription::
      property_next (Type const& o)
      {
        property_post (o);
        property_pre (o);
      }

      void ConnectionResourceDeploymentDescription::
      property_post (Type const&)
      {
        pop_ ();
      }

      // PlanConnectionDescription
      //
      //

      PlanConnectionDescription::
      PlanConnectionDescription (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      PlanConnectionDescription::
      PlanConnectionDescription ()
      {
      }

      void PlanConnectionDescription::
      traverse (Type const& o)
      {
        Traversal::PlanConnectionDescription::traverse (o);
      }

      void PlanConnectionDescription::
      name (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("name", top_ ()));
        Traversal::PlanConnectionDescription::name (o);
        pop_ ();
      }

      void PlanConnectionDescription::
      source (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("source", top_ ()));
        Traversal::PlanConnectionDescription::source (o);
        pop_ ();
      }

      void PlanConnectionDescription::
      deployRequirement_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("deployRequirement", top_ ()));
      }

      void PlanConnectionDescription::
      deployRequirement_next (Type const& o)
      {
        deployRequirement_post (o);
        deployRequirement_pre (o);
      }

      void PlanConnectionDescription::
      deployRequirement_post (Type const&)
      {
        pop_ ();
      }

      void PlanConnectionDescription::
      externalEndpoint_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("externalEndpoint", top_ ()));
      }

      void PlanConnectionDescription::
      externalEndpoint_next (Type const& o)
      {
        externalEndpoint_post (o);
        externalEndpoint_pre (o);
      }

      void PlanConnectionDescription::
      externalEndpoint_post (Type const&)
      {
        pop_ ();
      }

      void PlanConnectionDescription::
      internalEndpoint_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("internalEndpoint", top_ ()));
      }

      void PlanConnectionDescription::
      internalEndpoint_next (Type const& o)
      {
        internalEndpoint_post (o);
        internalEndpoint_pre (o);
      }

      void PlanConnectionDescription::
      internalEndpoint_post (Type const&)
      {
        pop_ ();
      }

      void PlanConnectionDescription::
      externalReference_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("externalReference", top_ ()));
      }

      void PlanConnectionDescription::
      externalReference_next (Type const& o)
      {
        externalReference_post (o);
        externalReference_pre (o);
      }

      void PlanConnectionDescription::
      externalReference_post (Type const&)
      {
        pop_ ();
      }

      void PlanConnectionDescription::
      deployedResource_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("deployedResource", top_ ()));
      }

      void PlanConnectionDescription::
      deployedResource_next (Type const& o)
      {
        deployedResource_post (o);
        deployedResource_pre (o);
      }

      void PlanConnectionDescription::
      deployedResource_post (Type const&)
      {
        pop_ ();
      }

      // ImplementationDependency
      //
      //

      ImplementationDependency::
      ImplementationDependency (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      ImplementationDependency::
      ImplementationDependency ()
      {
      }

      void ImplementationDependency::
      traverse (Type const& o)
      {
        Traversal::ImplementationDependency::traverse (o);
      }

      void ImplementationDependency::
      requiredType (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("requiredType", top_ ()));
        Traversal::ImplementationDependency::requiredType (o);
        pop_ ();
      }

      // Capability
      //
      //

      Capability::
      Capability (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      Capability::
      Capability ()
      {
      }

      void Capability::
      traverse (Type const& o)
      {
        Traversal::Capability::traverse (o);
      }

      void Capability::
      name (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("name", top_ ()));
        Traversal::Capability::name (o);
        pop_ ();
      }

      void Capability::
      resourceType_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("resourceType", top_ ()));
      }

      void Capability::
      resourceType_next (Type const& o)
      {
        resourceType_post (o);
        resourceType_pre (o);
      }

      void Capability::
      resourceType_post (Type const&)
      {
        pop_ ();
      }

      void Capability::
      property_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("property", top_ ()));
      }

      void Capability::
      property_next (Type const& o)
      {
        property_post (o);
        property_pre (o);
      }

      void Capability::
      property_post (Type const&)
      {
        pop_ ();
      }

      // ImplementationRequirement
      //
      //

      ImplementationRequirement::
      ImplementationRequirement (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      ImplementationRequirement::
      ImplementationRequirement ()
      {
      }

      void ImplementationRequirement::
      traverse (Type const& o)
      {
        Traversal::ImplementationRequirement::traverse (o);
      }

      void ImplementationRequirement::
      resourceUsage (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("resourceUsage", top_ ()));
        Traversal::ImplementationRequirement::resourceUsage (o);
        pop_ ();
      }

      void ImplementationRequirement::
      resourcePort (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("resourcePort", top_ ()));
        Traversal::ImplementationRequirement::resourcePort (o);
        pop_ ();
      }

      void ImplementationRequirement::
      componentPort (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("componentPort", top_ ()));
        Traversal::ImplementationRequirement::componentPort (o);
        pop_ ();
      }

      void ImplementationRequirement::
      resourceType (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("resourceType", top_ ()));
        Traversal::ImplementationRequirement::resourceType (o);
        pop_ ();
      }

      void ImplementationRequirement::
      name (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("name", top_ ()));
        Traversal::ImplementationRequirement::name (o);
        pop_ ();
      }

      void ImplementationRequirement::
      property_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("property", top_ ()));
      }

      void ImplementationRequirement::
      property_next (Type const& o)
      {
        property_post (o);
        property_pre (o);
      }

      void ImplementationRequirement::
      property_post (Type const&)
      {
        pop_ ();
      }

      // ComponentPackageReference
      //
      //

      ComponentPackageReference::
      ComponentPackageReference (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      ComponentPackageReference::
      ComponentPackageReference ()
      {
      }

      void ComponentPackageReference::
      traverse (Type const& o)
      {
        Traversal::ComponentPackageReference::traverse (o);
      }

      void ComponentPackageReference::
      requiredUUID (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("requiredUUID", top_ ()));
        Traversal::ComponentPackageReference::requiredUUID (o);
        pop_ ();
      }

      void ComponentPackageReference::
      requiredName (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("requiredName", top_ ()));
        Traversal::ComponentPackageReference::requiredName (o);
        pop_ ();
      }

      void ComponentPackageReference::
      requiredType (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("requiredType", top_ ()));
        Traversal::ComponentPackageReference::requiredType (o);
        pop_ ();
      }

      // SubcomponentPortEndpoint
      //
      //

      SubcomponentPortEndpoint::
      SubcomponentPortEndpoint (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      SubcomponentPortEndpoint::
      SubcomponentPortEndpoint ()
      {
      }

      void SubcomponentPortEndpoint::
      traverse (Type const& o)
      {
        Traversal::SubcomponentPortEndpoint::traverse (o);
      }

      void SubcomponentPortEndpoint::
      portName (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("portName", top_ ()));
        Traversal::SubcomponentPortEndpoint::portName (o);
        pop_ ();
      }

      void SubcomponentPortEndpoint::
      instance (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("instance", top_ ()));
        Traversal::SubcomponentPortEndpoint::instance (o);
        pop_ ();
      }

      // AssemblyConnectionDescription
      //
      //

      AssemblyConnectionDescription::
      AssemblyConnectionDescription (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      AssemblyConnectionDescription::
      AssemblyConnectionDescription ()
      {
      }

      void AssemblyConnectionDescription::
      traverse (Type const& o)
      {
        Traversal::AssemblyConnectionDescription::traverse (o);
      }

      void AssemblyConnectionDescription::
      name (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("name", top_ ()));
        Traversal::AssemblyConnectionDescription::name (o);
        pop_ ();
      }

      void AssemblyConnectionDescription::
      deployRequirement_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("deployRequirement", top_ ()));
      }

      void AssemblyConnectionDescription::
      deployRequirement_next (Type const& o)
      {
        deployRequirement_post (o);
        deployRequirement_pre (o);
      }

      void AssemblyConnectionDescription::
      deployRequirement_post (Type const&)
      {
        pop_ ();
      }

      void AssemblyConnectionDescription::
      internalEndpoint_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("internalEndpoint", top_ ()));
      }

      void AssemblyConnectionDescription::
      internalEndpoint_next (Type const& o)
      {
        internalEndpoint_post (o);
        internalEndpoint_pre (o);
      }

      void AssemblyConnectionDescription::
      internalEndpoint_post (Type const&)
      {
        pop_ ();
      }

      void AssemblyConnectionDescription::
      externalEndpoint_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("externalEndpoint", top_ ()));
      }

      void AssemblyConnectionDescription::
      externalEndpoint_next (Type const& o)
      {
        externalEndpoint_post (o);
        externalEndpoint_pre (o);
      }

      void AssemblyConnectionDescription::
      externalEndpoint_post (Type const&)
      {
        pop_ ();
      }

      void AssemblyConnectionDescription::
      externalReference_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("externalReference", top_ ()));
      }

      void AssemblyConnectionDescription::
      externalReference_next (Type const& o)
      {
        externalReference_post (o);
        externalReference_pre (o);
      }

      void AssemblyConnectionDescription::
      externalReference_post (Type const&)
      {
        pop_ ();
      }
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
  }
}

