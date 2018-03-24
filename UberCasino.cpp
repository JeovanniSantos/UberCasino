//******************************************************************
// 
//  Generated by IDL to C++ Translator
//  
//  File name: UberCasino.cpp
//  Source: idl/UberCasino.idl
//  Generated: Fri Mar 23 00:59:51 2018
//  OpenSplice V6.4.140320OSS
//  
//******************************************************************

#include "UberCasino.h"


#if DDS_USE_EXPLICIT_TEMPLATES
template class DDS_DCPS_FArray_var< UberCasino::Game::_dealer_cards, UberCasino::Game::_dealer_cards_slice, struct UberCasino::Game::_dealer_cards_uniq_>;
template class DDS_DCPS_Array_forany< UberCasino::Game::_dealer_cards, UberCasino::Game::_dealer_cards_slice, struct UberCasino::Game::_dealer_cards_uniq_>;
#endif

template <>
UberCasino::Game::_dealer_cards_slice* DDS_DCPS_ArrayHelper < UberCasino::Game::_dealer_cards, UberCasino::Game::_dealer_cards_slice, UberCasino::Game::_dealer_cards_uniq_>::alloc ()
{
   return UberCasino::Game::_dealer_cards_alloc ();
}

template <>
void DDS_DCPS_ArrayHelper < UberCasino::Game::_dealer_cards, UberCasino::Game::_dealer_cards_slice, UberCasino::Game::_dealer_cards_uniq_>::copy (UberCasino::Game::_dealer_cards_slice *to, const UberCasino::Game::_dealer_cards_slice* from)
{
   UberCasino::Game::_dealer_cards_copy (to, from);
}

template <>
void DDS_DCPS_ArrayHelper < UberCasino::Game::_dealer_cards, UberCasino::Game::_dealer_cards_slice, UberCasino::Game::_dealer_cards_uniq_>::free (UberCasino::Game::_dealer_cards_slice *ptr)
{
   UberCasino::Game::_dealer_cards_free (ptr);
}

UberCasino::Game::_dealer_cards_slice * UberCasino::Game::_dealer_cards_alloc ()
{
   UberCasino::card_t * ret = (UberCasino::card_t*) new UberCasino::card_t [10];
   return (_dealer_cards_slice *) ret;
}

void UberCasino::Game::_dealer_cards_free (_dealer_cards_slice * s)
{
   delete [] s;
}

void UberCasino::Game::_dealer_cards_copy
(
   _dealer_cards_slice * to,
   const _dealer_cards_slice * from
)
{
   const UberCasino::card_t* sv = ( const UberCasino::card_t*) from;
   UberCasino::card_t* tv = (UberCasino::card_t*) to;
   for (DDS::ULong i = 0; i < 10; i++) tv[i] = sv[i];
}

UberCasino::Game::_dealer_cards_slice * UberCasino::Game::_dealer_cards_dup
   (const _dealer_cards_slice * from)
{
   _dealer_cards_slice * to = _dealer_cards_alloc ();
   _dealer_cards_copy (to, from);
   return to;
}


#if DDS_USE_EXPLICIT_TEMPLATES
template class DDS_DCPS_FArray_var< UberCasino::Game::_p, UberCasino::Game::_p_slice, struct UberCasino::Game::_p_uniq_>;
template class DDS_DCPS_Array_forany< UberCasino::Game::_p, UberCasino::Game::_p_slice, struct UberCasino::Game::_p_uniq_>;
#endif

template <>
UberCasino::Game::_p_slice* DDS_DCPS_ArrayHelper < UberCasino::Game::_p, UberCasino::Game::_p_slice, UberCasino::Game::_p_uniq_>::alloc ()
{
   return UberCasino::Game::_p_alloc ();
}

template <>
void DDS_DCPS_ArrayHelper < UberCasino::Game::_p, UberCasino::Game::_p_slice, UberCasino::Game::_p_uniq_>::copy (UberCasino::Game::_p_slice *to, const UberCasino::Game::_p_slice* from)
{
   UberCasino::Game::_p_copy (to, from);
}

template <>
void DDS_DCPS_ArrayHelper < UberCasino::Game::_p, UberCasino::Game::_p_slice, UberCasino::Game::_p_uniq_>::free (UberCasino::Game::_p_slice *ptr)
{
   UberCasino::Game::_p_free (ptr);
}

UberCasino::Game::_p_slice * UberCasino::Game::_p_alloc ()
{
   UberCasino::PlayerState * ret = (UberCasino::PlayerState*) new UberCasino::PlayerState [7];
   return (_p_slice *) ret;
}

void UberCasino::Game::_p_free (_p_slice * s)
{
   delete [] s;
}

void UberCasino::Game::_p_copy
(
   _p_slice * to,
   const _p_slice * from
)
{
   const UberCasino::PlayerState* sv = ( const UberCasino::PlayerState*) from;
   UberCasino::PlayerState* tv = (UberCasino::PlayerState*) to;
   for (DDS::ULong i = 0; i < 7; i++) tv[i] = sv[i];
}

UberCasino::Game::_p_slice * UberCasino::Game::_p_dup
   (const _p_slice * from)
{
   _p_slice * to = _p_alloc ();
   _p_copy (to, from);
   return to;
}


#if DDS_USE_EXPLICIT_TEMPLATES
template class DDS_DCPS_FArray_var< UberCasino::Game::_dealer_uid, UberCasino::Game::_dealer_uid_slice, struct UberCasino::Game::_dealer_uid_uniq_>;
template class DDS_DCPS_Array_forany< UberCasino::Game::_dealer_uid, UberCasino::Game::_dealer_uid_slice, struct UberCasino::Game::_dealer_uid_uniq_>;
#endif

template <>
UberCasino::Game::_dealer_uid_slice* DDS_DCPS_ArrayHelper < UberCasino::Game::_dealer_uid, UberCasino::Game::_dealer_uid_slice, UberCasino::Game::_dealer_uid_uniq_>::alloc ()
{
   return UberCasino::Game::_dealer_uid_alloc ();
}

template <>
void DDS_DCPS_ArrayHelper < UberCasino::Game::_dealer_uid, UberCasino::Game::_dealer_uid_slice, UberCasino::Game::_dealer_uid_uniq_>::copy (UberCasino::Game::_dealer_uid_slice *to, const UberCasino::Game::_dealer_uid_slice* from)
{
   UberCasino::Game::_dealer_uid_copy (to, from);
}

template <>
void DDS_DCPS_ArrayHelper < UberCasino::Game::_dealer_uid, UberCasino::Game::_dealer_uid_slice, UberCasino::Game::_dealer_uid_uniq_>::free (UberCasino::Game::_dealer_uid_slice *ptr)
{
   UberCasino::Game::_dealer_uid_free (ptr);
}

UberCasino::Game::_dealer_uid_slice * UberCasino::Game::_dealer_uid_alloc ()
{
   DDS::Char * ret = (DDS::Char*) new DDS::Char [8];
   return (_dealer_uid_slice *) ret;
}

void UberCasino::Game::_dealer_uid_free (_dealer_uid_slice * s)
{
   delete [] s;
}

void UberCasino::Game::_dealer_uid_copy
(
   _dealer_uid_slice * to,
   const _dealer_uid_slice * from
)
{
   const DDS::Char* sv = ( const DDS::Char*) from;
   DDS::Char* tv = (DDS::Char*) to;
   for (DDS::ULong i = 0; i < 8; i++) tv[i] = sv[i];
}

UberCasino::Game::_dealer_uid_slice * UberCasino::Game::_dealer_uid_dup
   (const _dealer_uid_slice * from)
{
   _dealer_uid_slice * to = _dealer_uid_alloc ();
   _dealer_uid_copy (to, from);
   return to;
}


#if DDS_USE_EXPLICIT_TEMPLATES
template class DDS_DCPS_FArray_var< UberCasino::Game::_game_uid, UberCasino::Game::_game_uid_slice, struct UberCasino::Game::_game_uid_uniq_>;
template class DDS_DCPS_Array_forany< UberCasino::Game::_game_uid, UberCasino::Game::_game_uid_slice, struct UberCasino::Game::_game_uid_uniq_>;
#endif

template <>
UberCasino::Game::_game_uid_slice* DDS_DCPS_ArrayHelper < UberCasino::Game::_game_uid, UberCasino::Game::_game_uid_slice, UberCasino::Game::_game_uid_uniq_>::alloc ()
{
   return UberCasino::Game::_game_uid_alloc ();
}

template <>
void DDS_DCPS_ArrayHelper < UberCasino::Game::_game_uid, UberCasino::Game::_game_uid_slice, UberCasino::Game::_game_uid_uniq_>::copy (UberCasino::Game::_game_uid_slice *to, const UberCasino::Game::_game_uid_slice* from)
{
   UberCasino::Game::_game_uid_copy (to, from);
}

template <>
void DDS_DCPS_ArrayHelper < UberCasino::Game::_game_uid, UberCasino::Game::_game_uid_slice, UberCasino::Game::_game_uid_uniq_>::free (UberCasino::Game::_game_uid_slice *ptr)
{
   UberCasino::Game::_game_uid_free (ptr);
}

UberCasino::Game::_game_uid_slice * UberCasino::Game::_game_uid_alloc ()
{
   DDS::Char * ret = (DDS::Char*) new DDS::Char [8];
   return (_game_uid_slice *) ret;
}

void UberCasino::Game::_game_uid_free (_game_uid_slice * s)
{
   delete [] s;
}

void UberCasino::Game::_game_uid_copy
(
   _game_uid_slice * to,
   const _game_uid_slice * from
)
{
   const DDS::Char* sv = ( const DDS::Char*) from;
   DDS::Char* tv = (DDS::Char*) to;
   for (DDS::ULong i = 0; i < 8; i++) tv[i] = sv[i];
}

UberCasino::Game::_game_uid_slice * UberCasino::Game::_game_uid_dup
   (const _game_uid_slice * from)
{
   _game_uid_slice * to = _game_uid_alloc ();
   _game_uid_copy (to, from);
   return to;
}


#if DDS_USE_EXPLICIT_TEMPLATES
template class DDS_DCPS_FArray_var< UberCasino::PlayerState::_cards, UberCasino::PlayerState::_cards_slice, struct UberCasino::PlayerState::_cards_uniq_>;
template class DDS_DCPS_Array_forany< UberCasino::PlayerState::_cards, UberCasino::PlayerState::_cards_slice, struct UberCasino::PlayerState::_cards_uniq_>;
#endif

template <>
UberCasino::PlayerState::_cards_slice* DDS_DCPS_ArrayHelper < UberCasino::PlayerState::_cards, UberCasino::PlayerState::_cards_slice, UberCasino::PlayerState::_cards_uniq_>::alloc ()
{
   return UberCasino::PlayerState::_cards_alloc ();
}

template <>
void DDS_DCPS_ArrayHelper < UberCasino::PlayerState::_cards, UberCasino::PlayerState::_cards_slice, UberCasino::PlayerState::_cards_uniq_>::copy (UberCasino::PlayerState::_cards_slice *to, const UberCasino::PlayerState::_cards_slice* from)
{
   UberCasino::PlayerState::_cards_copy (to, from);
}

template <>
void DDS_DCPS_ArrayHelper < UberCasino::PlayerState::_cards, UberCasino::PlayerState::_cards_slice, UberCasino::PlayerState::_cards_uniq_>::free (UberCasino::PlayerState::_cards_slice *ptr)
{
   UberCasino::PlayerState::_cards_free (ptr);
}

UberCasino::PlayerState::_cards_slice * UberCasino::PlayerState::_cards_alloc ()
{
   UberCasino::card_t * ret = (UberCasino::card_t*) new UberCasino::card_t [10];
   return (_cards_slice *) ret;
}

void UberCasino::PlayerState::_cards_free (_cards_slice * s)
{
   delete [] s;
}

void UberCasino::PlayerState::_cards_copy
(
   _cards_slice * to,
   const _cards_slice * from
)
{
   const UberCasino::card_t* sv = ( const UberCasino::card_t*) from;
   UberCasino::card_t* tv = (UberCasino::card_t*) to;
   for (DDS::ULong i = 0; i < 10; i++) tv[i] = sv[i];
}

UberCasino::PlayerState::_cards_slice * UberCasino::PlayerState::_cards_dup
   (const _cards_slice * from)
{
   _cards_slice * to = _cards_alloc ();
   _cards_copy (to, from);
   return to;
}


#if DDS_USE_EXPLICIT_TEMPLATES
template class DDS_DCPS_FArray_var< UberCasino::PlayerState::_uuid, UberCasino::PlayerState::_uuid_slice, struct UberCasino::PlayerState::_uuid_uniq_>;
template class DDS_DCPS_Array_forany< UberCasino::PlayerState::_uuid, UberCasino::PlayerState::_uuid_slice, struct UberCasino::PlayerState::_uuid_uniq_>;
#endif

template <>
UberCasino::PlayerState::_uuid_slice* DDS_DCPS_ArrayHelper < UberCasino::PlayerState::_uuid, UberCasino::PlayerState::_uuid_slice, UberCasino::PlayerState::_uuid_uniq_>::alloc ()
{
   return UberCasino::PlayerState::_uuid_alloc ();
}

template <>
void DDS_DCPS_ArrayHelper < UberCasino::PlayerState::_uuid, UberCasino::PlayerState::_uuid_slice, UberCasino::PlayerState::_uuid_uniq_>::copy (UberCasino::PlayerState::_uuid_slice *to, const UberCasino::PlayerState::_uuid_slice* from)
{
   UberCasino::PlayerState::_uuid_copy (to, from);
}

template <>
void DDS_DCPS_ArrayHelper < UberCasino::PlayerState::_uuid, UberCasino::PlayerState::_uuid_slice, UberCasino::PlayerState::_uuid_uniq_>::free (UberCasino::PlayerState::_uuid_slice *ptr)
{
   UberCasino::PlayerState::_uuid_free (ptr);
}

UberCasino::PlayerState::_uuid_slice * UberCasino::PlayerState::_uuid_alloc ()
{
   DDS::Char * ret = (DDS::Char*) new DDS::Char [8];
   return (_uuid_slice *) ret;
}

void UberCasino::PlayerState::_uuid_free (_uuid_slice * s)
{
   delete [] s;
}

void UberCasino::PlayerState::_uuid_copy
(
   _uuid_slice * to,
   const _uuid_slice * from
)
{
   const DDS::Char* sv = ( const DDS::Char*) from;
   DDS::Char* tv = (DDS::Char*) to;
   for (DDS::ULong i = 0; i < 8; i++) tv[i] = sv[i];
}

UberCasino::PlayerState::_uuid_slice * UberCasino::PlayerState::_uuid_dup
   (const _uuid_slice * from)
{
   _uuid_slice * to = _uuid_alloc ();
   _uuid_copy (to, from);
   return to;
}


#if DDS_USE_EXPLICIT_TEMPLATES
template class DDS_DCPS_FArray_var< UberCasino::Dealer::_game_uuid, UberCasino::Dealer::_game_uuid_slice, struct UberCasino::Dealer::_game_uuid_uniq_>;
template class DDS_DCPS_Array_forany< UberCasino::Dealer::_game_uuid, UberCasino::Dealer::_game_uuid_slice, struct UberCasino::Dealer::_game_uuid_uniq_>;
#endif

template <>
UberCasino::Dealer::_game_uuid_slice* DDS_DCPS_ArrayHelper < UberCasino::Dealer::_game_uuid, UberCasino::Dealer::_game_uuid_slice, UberCasino::Dealer::_game_uuid_uniq_>::alloc ()
{
   return UberCasino::Dealer::_game_uuid_alloc ();
}

template <>
void DDS_DCPS_ArrayHelper < UberCasino::Dealer::_game_uuid, UberCasino::Dealer::_game_uuid_slice, UberCasino::Dealer::_game_uuid_uniq_>::copy (UberCasino::Dealer::_game_uuid_slice *to, const UberCasino::Dealer::_game_uuid_slice* from)
{
   UberCasino::Dealer::_game_uuid_copy (to, from);
}

template <>
void DDS_DCPS_ArrayHelper < UberCasino::Dealer::_game_uuid, UberCasino::Dealer::_game_uuid_slice, UberCasino::Dealer::_game_uuid_uniq_>::free (UberCasino::Dealer::_game_uuid_slice *ptr)
{
   UberCasino::Dealer::_game_uuid_free (ptr);
}

UberCasino::Dealer::_game_uuid_slice * UberCasino::Dealer::_game_uuid_alloc ()
{
   DDS::Char * ret = (DDS::Char*) new DDS::Char [8];
   return (_game_uuid_slice *) ret;
}

void UberCasino::Dealer::_game_uuid_free (_game_uuid_slice * s)
{
   delete [] s;
}

void UberCasino::Dealer::_game_uuid_copy
(
   _game_uuid_slice * to,
   const _game_uuid_slice * from
)
{
   const DDS::Char* sv = ( const DDS::Char*) from;
   DDS::Char* tv = (DDS::Char*) to;
   for (DDS::ULong i = 0; i < 8; i++) tv[i] = sv[i];
}

UberCasino::Dealer::_game_uuid_slice * UberCasino::Dealer::_game_uuid_dup
   (const _game_uuid_slice * from)
{
   _game_uuid_slice * to = _game_uuid_alloc ();
   _game_uuid_copy (to, from);
   return to;
}


#if DDS_USE_EXPLICIT_TEMPLATES
template class DDS_DCPS_FArray_var< UberCasino::Dealer::_name, UberCasino::Dealer::_name_slice, struct UberCasino::Dealer::_name_uniq_>;
template class DDS_DCPS_Array_forany< UberCasino::Dealer::_name, UberCasino::Dealer::_name_slice, struct UberCasino::Dealer::_name_uniq_>;
#endif

template <>
UberCasino::Dealer::_name_slice* DDS_DCPS_ArrayHelper < UberCasino::Dealer::_name, UberCasino::Dealer::_name_slice, UberCasino::Dealer::_name_uniq_>::alloc ()
{
   return UberCasino::Dealer::_name_alloc ();
}

template <>
void DDS_DCPS_ArrayHelper < UberCasino::Dealer::_name, UberCasino::Dealer::_name_slice, UberCasino::Dealer::_name_uniq_>::copy (UberCasino::Dealer::_name_slice *to, const UberCasino::Dealer::_name_slice* from)
{
   UberCasino::Dealer::_name_copy (to, from);
}

template <>
void DDS_DCPS_ArrayHelper < UberCasino::Dealer::_name, UberCasino::Dealer::_name_slice, UberCasino::Dealer::_name_uniq_>::free (UberCasino::Dealer::_name_slice *ptr)
{
   UberCasino::Dealer::_name_free (ptr);
}

UberCasino::Dealer::_name_slice * UberCasino::Dealer::_name_alloc ()
{
   DDS::Char * ret = (DDS::Char*) new DDS::Char [32];
   return (_name_slice *) ret;
}

void UberCasino::Dealer::_name_free (_name_slice * s)
{
   delete [] s;
}

void UberCasino::Dealer::_name_copy
(
   _name_slice * to,
   const _name_slice * from
)
{
   const DDS::Char* sv = ( const DDS::Char*) from;
   DDS::Char* tv = (DDS::Char*) to;
   for (DDS::ULong i = 0; i < 32; i++) tv[i] = sv[i];
}

UberCasino::Dealer::_name_slice * UberCasino::Dealer::_name_dup
   (const _name_slice * from)
{
   _name_slice * to = _name_alloc ();
   _name_copy (to, from);
   return to;
}


#if DDS_USE_EXPLICIT_TEMPLATES
template class DDS_DCPS_FArray_var< UberCasino::Dealer::_uuid, UberCasino::Dealer::_uuid_slice, struct UberCasino::Dealer::_uuid_uniq_>;
template class DDS_DCPS_Array_forany< UberCasino::Dealer::_uuid, UberCasino::Dealer::_uuid_slice, struct UberCasino::Dealer::_uuid_uniq_>;
#endif

template <>
UberCasino::Dealer::_uuid_slice* DDS_DCPS_ArrayHelper < UberCasino::Dealer::_uuid, UberCasino::Dealer::_uuid_slice, UberCasino::Dealer::_uuid_uniq_>::alloc ()
{
   return UberCasino::Dealer::_uuid_alloc ();
}

template <>
void DDS_DCPS_ArrayHelper < UberCasino::Dealer::_uuid, UberCasino::Dealer::_uuid_slice, UberCasino::Dealer::_uuid_uniq_>::copy (UberCasino::Dealer::_uuid_slice *to, const UberCasino::Dealer::_uuid_slice* from)
{
   UberCasino::Dealer::_uuid_copy (to, from);
}

template <>
void DDS_DCPS_ArrayHelper < UberCasino::Dealer::_uuid, UberCasino::Dealer::_uuid_slice, UberCasino::Dealer::_uuid_uniq_>::free (UberCasino::Dealer::_uuid_slice *ptr)
{
   UberCasino::Dealer::_uuid_free (ptr);
}

UberCasino::Dealer::_uuid_slice * UberCasino::Dealer::_uuid_alloc ()
{
   DDS::Char * ret = (DDS::Char*) new DDS::Char [8];
   return (_uuid_slice *) ret;
}

void UberCasino::Dealer::_uuid_free (_uuid_slice * s)
{
   delete [] s;
}

void UberCasino::Dealer::_uuid_copy
(
   _uuid_slice * to,
   const _uuid_slice * from
)
{
   const DDS::Char* sv = ( const DDS::Char*) from;
   DDS::Char* tv = (DDS::Char*) to;
   for (DDS::ULong i = 0; i < 8; i++) tv[i] = sv[i];
}

UberCasino::Dealer::_uuid_slice * UberCasino::Dealer::_uuid_dup
   (const _uuid_slice * from)
{
   _uuid_slice * to = _uuid_alloc ();
   _uuid_copy (to, from);
   return to;
}


#if DDS_USE_EXPLICIT_TEMPLATES
template class DDS_DCPS_FArray_var< UberCasino::Player::_name, UberCasino::Player::_name_slice, struct UberCasino::Player::_name_uniq_>;
template class DDS_DCPS_Array_forany< UberCasino::Player::_name, UberCasino::Player::_name_slice, struct UberCasino::Player::_name_uniq_>;
#endif

template <>
UberCasino::Player::_name_slice* DDS_DCPS_ArrayHelper < UberCasino::Player::_name, UberCasino::Player::_name_slice, UberCasino::Player::_name_uniq_>::alloc ()
{
   return UberCasino::Player::_name_alloc ();
}

template <>
void DDS_DCPS_ArrayHelper < UberCasino::Player::_name, UberCasino::Player::_name_slice, UberCasino::Player::_name_uniq_>::copy (UberCasino::Player::_name_slice *to, const UberCasino::Player::_name_slice* from)
{
   UberCasino::Player::_name_copy (to, from);
}

template <>
void DDS_DCPS_ArrayHelper < UberCasino::Player::_name, UberCasino::Player::_name_slice, UberCasino::Player::_name_uniq_>::free (UberCasino::Player::_name_slice *ptr)
{
   UberCasino::Player::_name_free (ptr);
}

UberCasino::Player::_name_slice * UberCasino::Player::_name_alloc ()
{
   DDS::Char * ret = (DDS::Char*) new DDS::Char [32];
   return (_name_slice *) ret;
}

void UberCasino::Player::_name_free (_name_slice * s)
{
   delete [] s;
}

void UberCasino::Player::_name_copy
(
   _name_slice * to,
   const _name_slice * from
)
{
   const DDS::Char* sv = ( const DDS::Char*) from;
   DDS::Char* tv = (DDS::Char*) to;
   for (DDS::ULong i = 0; i < 32; i++) tv[i] = sv[i];
}

UberCasino::Player::_name_slice * UberCasino::Player::_name_dup
   (const _name_slice * from)
{
   _name_slice * to = _name_alloc ();
   _name_copy (to, from);
   return to;
}


#if DDS_USE_EXPLICIT_TEMPLATES
template class DDS_DCPS_FArray_var< UberCasino::Player::_uuid, UberCasino::Player::_uuid_slice, struct UberCasino::Player::_uuid_uniq_>;
template class DDS_DCPS_Array_forany< UberCasino::Player::_uuid, UberCasino::Player::_uuid_slice, struct UberCasino::Player::_uuid_uniq_>;
#endif

template <>
UberCasino::Player::_uuid_slice* DDS_DCPS_ArrayHelper < UberCasino::Player::_uuid, UberCasino::Player::_uuid_slice, UberCasino::Player::_uuid_uniq_>::alloc ()
{
   return UberCasino::Player::_uuid_alloc ();
}

template <>
void DDS_DCPS_ArrayHelper < UberCasino::Player::_uuid, UberCasino::Player::_uuid_slice, UberCasino::Player::_uuid_uniq_>::copy (UberCasino::Player::_uuid_slice *to, const UberCasino::Player::_uuid_slice* from)
{
   UberCasino::Player::_uuid_copy (to, from);
}

template <>
void DDS_DCPS_ArrayHelper < UberCasino::Player::_uuid, UberCasino::Player::_uuid_slice, UberCasino::Player::_uuid_uniq_>::free (UberCasino::Player::_uuid_slice *ptr)
{
   UberCasino::Player::_uuid_free (ptr);
}

UberCasino::Player::_uuid_slice * UberCasino::Player::_uuid_alloc ()
{
   DDS::Char * ret = (DDS::Char*) new DDS::Char [8];
   return (_uuid_slice *) ret;
}

void UberCasino::Player::_uuid_free (_uuid_slice * s)
{
   delete [] s;
}

void UberCasino::Player::_uuid_copy
(
   _uuid_slice * to,
   const _uuid_slice * from
)
{
   const DDS::Char* sv = ( const DDS::Char*) from;
   DDS::Char* tv = (DDS::Char*) to;
   for (DDS::ULong i = 0; i < 8; i++) tv[i] = sv[i];
}

UberCasino::Player::_uuid_slice * UberCasino::Player::_uuid_dup
   (const _uuid_slice * from)
{
   _uuid_slice * to = _uuid_alloc ();
   _uuid_copy (to, from);
   return to;
}




