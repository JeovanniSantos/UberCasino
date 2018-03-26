//******************************************************************
// 
//  Generated by IDL to C++ Translator
//  
//  File name: UberCasinoDcps.cpp
//  Source: UberCasinoDcps.idl
//  Generated: Sun Mar 25 23:09:36 2018
//  OpenSplice V6.4.140320OSS
//  
//******************************************************************

#include "UberCasinoDcps.h"

#if DDS_USE_EXPLICIT_TEMPLATES
template class DDS_DCPSUFLSeq < UberCasino::Game, struct GameSeq_uniq_>;
#endif
#if DDS_USE_EXPLICIT_TEMPLATES
template class DDS_DCPSUFLSeq < UberCasino::Dealer, struct DealerSeq_uniq_>;
#endif
#if DDS_USE_EXPLICIT_TEMPLATES
template class DDS_DCPSUFLSeq < UberCasino::Player, struct PlayerSeq_uniq_>;
#endif

const char * UberCasino::PlayerTypeSupportInterface::_local_id = "IDL:UberCasino/PlayerTypeSupportInterface:1.0";

UberCasino::PlayerTypeSupportInterface_ptr UberCasino::PlayerTypeSupportInterface::_duplicate (UberCasino::PlayerTypeSupportInterface_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean UberCasino::PlayerTypeSupportInterface::_local_is_a (const char * _id)
{
   if (strcmp (_id, UberCasino::PlayerTypeSupportInterface::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::TypeSupport NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

UberCasino::PlayerTypeSupportInterface_ptr UberCasino::PlayerTypeSupportInterface::_narrow (DDS::Object_ptr p)
{
   UberCasino::PlayerTypeSupportInterface_ptr result = NULL;
   if (p && p->_is_a (UberCasino::PlayerTypeSupportInterface::_local_id))
   {
      result = dynamic_cast < UberCasino::PlayerTypeSupportInterface_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

UberCasino::PlayerTypeSupportInterface_ptr UberCasino::PlayerTypeSupportInterface::_unchecked_narrow (DDS::Object_ptr p)
{
   UberCasino::PlayerTypeSupportInterface_ptr result;
   result = dynamic_cast < UberCasino::PlayerTypeSupportInterface_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * UberCasino::PlayerDataWriter::_local_id = "IDL:UberCasino/PlayerDataWriter:1.0";

UberCasino::PlayerDataWriter_ptr UberCasino::PlayerDataWriter::_duplicate (UberCasino::PlayerDataWriter_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean UberCasino::PlayerDataWriter::_local_is_a (const char * _id)
{
   if (strcmp (_id, UberCasino::PlayerDataWriter::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::DataWriter NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

UberCasino::PlayerDataWriter_ptr UberCasino::PlayerDataWriter::_narrow (DDS::Object_ptr p)
{
   UberCasino::PlayerDataWriter_ptr result = NULL;
   if (p && p->_is_a (UberCasino::PlayerDataWriter::_local_id))
   {
      result = dynamic_cast < UberCasino::PlayerDataWriter_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

UberCasino::PlayerDataWriter_ptr UberCasino::PlayerDataWriter::_unchecked_narrow (DDS::Object_ptr p)
{
   UberCasino::PlayerDataWriter_ptr result;
   result = dynamic_cast < UberCasino::PlayerDataWriter_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * UberCasino::PlayerDataReader::_local_id = "IDL:UberCasino/PlayerDataReader:1.0";

UberCasino::PlayerDataReader_ptr UberCasino::PlayerDataReader::_duplicate (UberCasino::PlayerDataReader_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean UberCasino::PlayerDataReader::_local_is_a (const char * _id)
{
   if (strcmp (_id, UberCasino::PlayerDataReader::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::DataReader NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

UberCasino::PlayerDataReader_ptr UberCasino::PlayerDataReader::_narrow (DDS::Object_ptr p)
{
   UberCasino::PlayerDataReader_ptr result = NULL;
   if (p && p->_is_a (UberCasino::PlayerDataReader::_local_id))
   {
      result = dynamic_cast < UberCasino::PlayerDataReader_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

UberCasino::PlayerDataReader_ptr UberCasino::PlayerDataReader::_unchecked_narrow (DDS::Object_ptr p)
{
   UberCasino::PlayerDataReader_ptr result;
   result = dynamic_cast < UberCasino::PlayerDataReader_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * UberCasino::PlayerDataReaderView::_local_id = "IDL:UberCasino/PlayerDataReaderView:1.0";

UberCasino::PlayerDataReaderView_ptr UberCasino::PlayerDataReaderView::_duplicate (UberCasino::PlayerDataReaderView_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean UberCasino::PlayerDataReaderView::_local_is_a (const char * _id)
{
   if (strcmp (_id, UberCasino::PlayerDataReaderView::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::DataReaderView NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

UberCasino::PlayerDataReaderView_ptr UberCasino::PlayerDataReaderView::_narrow (DDS::Object_ptr p)
{
   UberCasino::PlayerDataReaderView_ptr result = NULL;
   if (p && p->_is_a (UberCasino::PlayerDataReaderView::_local_id))
   {
      result = dynamic_cast < UberCasino::PlayerDataReaderView_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

UberCasino::PlayerDataReaderView_ptr UberCasino::PlayerDataReaderView::_unchecked_narrow (DDS::Object_ptr p)
{
   UberCasino::PlayerDataReaderView_ptr result;
   result = dynamic_cast < UberCasino::PlayerDataReaderView_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * UberCasino::DealerTypeSupportInterface::_local_id = "IDL:UberCasino/DealerTypeSupportInterface:1.0";

UberCasino::DealerTypeSupportInterface_ptr UberCasino::DealerTypeSupportInterface::_duplicate (UberCasino::DealerTypeSupportInterface_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean UberCasino::DealerTypeSupportInterface::_local_is_a (const char * _id)
{
   if (strcmp (_id, UberCasino::DealerTypeSupportInterface::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::TypeSupport NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

UberCasino::DealerTypeSupportInterface_ptr UberCasino::DealerTypeSupportInterface::_narrow (DDS::Object_ptr p)
{
   UberCasino::DealerTypeSupportInterface_ptr result = NULL;
   if (p && p->_is_a (UberCasino::DealerTypeSupportInterface::_local_id))
   {
      result = dynamic_cast < UberCasino::DealerTypeSupportInterface_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

UberCasino::DealerTypeSupportInterface_ptr UberCasino::DealerTypeSupportInterface::_unchecked_narrow (DDS::Object_ptr p)
{
   UberCasino::DealerTypeSupportInterface_ptr result;
   result = dynamic_cast < UberCasino::DealerTypeSupportInterface_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * UberCasino::DealerDataWriter::_local_id = "IDL:UberCasino/DealerDataWriter:1.0";

UberCasino::DealerDataWriter_ptr UberCasino::DealerDataWriter::_duplicate (UberCasino::DealerDataWriter_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean UberCasino::DealerDataWriter::_local_is_a (const char * _id)
{
   if (strcmp (_id, UberCasino::DealerDataWriter::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::DataWriter NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

UberCasino::DealerDataWriter_ptr UberCasino::DealerDataWriter::_narrow (DDS::Object_ptr p)
{
   UberCasino::DealerDataWriter_ptr result = NULL;
   if (p && p->_is_a (UberCasino::DealerDataWriter::_local_id))
   {
      result = dynamic_cast < UberCasino::DealerDataWriter_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

UberCasino::DealerDataWriter_ptr UberCasino::DealerDataWriter::_unchecked_narrow (DDS::Object_ptr p)
{
   UberCasino::DealerDataWriter_ptr result;
   result = dynamic_cast < UberCasino::DealerDataWriter_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * UberCasino::DealerDataReader::_local_id = "IDL:UberCasino/DealerDataReader:1.0";

UberCasino::DealerDataReader_ptr UberCasino::DealerDataReader::_duplicate (UberCasino::DealerDataReader_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean UberCasino::DealerDataReader::_local_is_a (const char * _id)
{
   if (strcmp (_id, UberCasino::DealerDataReader::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::DataReader NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

UberCasino::DealerDataReader_ptr UberCasino::DealerDataReader::_narrow (DDS::Object_ptr p)
{
   UberCasino::DealerDataReader_ptr result = NULL;
   if (p && p->_is_a (UberCasino::DealerDataReader::_local_id))
   {
      result = dynamic_cast < UberCasino::DealerDataReader_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

UberCasino::DealerDataReader_ptr UberCasino::DealerDataReader::_unchecked_narrow (DDS::Object_ptr p)
{
   UberCasino::DealerDataReader_ptr result;
   result = dynamic_cast < UberCasino::DealerDataReader_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * UberCasino::DealerDataReaderView::_local_id = "IDL:UberCasino/DealerDataReaderView:1.0";

UberCasino::DealerDataReaderView_ptr UberCasino::DealerDataReaderView::_duplicate (UberCasino::DealerDataReaderView_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean UberCasino::DealerDataReaderView::_local_is_a (const char * _id)
{
   if (strcmp (_id, UberCasino::DealerDataReaderView::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::DataReaderView NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

UberCasino::DealerDataReaderView_ptr UberCasino::DealerDataReaderView::_narrow (DDS::Object_ptr p)
{
   UberCasino::DealerDataReaderView_ptr result = NULL;
   if (p && p->_is_a (UberCasino::DealerDataReaderView::_local_id))
   {
      result = dynamic_cast < UberCasino::DealerDataReaderView_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

UberCasino::DealerDataReaderView_ptr UberCasino::DealerDataReaderView::_unchecked_narrow (DDS::Object_ptr p)
{
   UberCasino::DealerDataReaderView_ptr result;
   result = dynamic_cast < UberCasino::DealerDataReaderView_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * UberCasino::GameTypeSupportInterface::_local_id = "IDL:UberCasino/GameTypeSupportInterface:1.0";

UberCasino::GameTypeSupportInterface_ptr UberCasino::GameTypeSupportInterface::_duplicate (UberCasino::GameTypeSupportInterface_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean UberCasino::GameTypeSupportInterface::_local_is_a (const char * _id)
{
   if (strcmp (_id, UberCasino::GameTypeSupportInterface::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::TypeSupport NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

UberCasino::GameTypeSupportInterface_ptr UberCasino::GameTypeSupportInterface::_narrow (DDS::Object_ptr p)
{
   UberCasino::GameTypeSupportInterface_ptr result = NULL;
   if (p && p->_is_a (UberCasino::GameTypeSupportInterface::_local_id))
   {
      result = dynamic_cast < UberCasino::GameTypeSupportInterface_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

UberCasino::GameTypeSupportInterface_ptr UberCasino::GameTypeSupportInterface::_unchecked_narrow (DDS::Object_ptr p)
{
   UberCasino::GameTypeSupportInterface_ptr result;
   result = dynamic_cast < UberCasino::GameTypeSupportInterface_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * UberCasino::GameDataWriter::_local_id = "IDL:UberCasino/GameDataWriter:1.0";

UberCasino::GameDataWriter_ptr UberCasino::GameDataWriter::_duplicate (UberCasino::GameDataWriter_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean UberCasino::GameDataWriter::_local_is_a (const char * _id)
{
   if (strcmp (_id, UberCasino::GameDataWriter::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::DataWriter NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

UberCasino::GameDataWriter_ptr UberCasino::GameDataWriter::_narrow (DDS::Object_ptr p)
{
   UberCasino::GameDataWriter_ptr result = NULL;
   if (p && p->_is_a (UberCasino::GameDataWriter::_local_id))
   {
      result = dynamic_cast < UberCasino::GameDataWriter_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

UberCasino::GameDataWriter_ptr UberCasino::GameDataWriter::_unchecked_narrow (DDS::Object_ptr p)
{
   UberCasino::GameDataWriter_ptr result;
   result = dynamic_cast < UberCasino::GameDataWriter_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * UberCasino::GameDataReader::_local_id = "IDL:UberCasino/GameDataReader:1.0";

UberCasino::GameDataReader_ptr UberCasino::GameDataReader::_duplicate (UberCasino::GameDataReader_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean UberCasino::GameDataReader::_local_is_a (const char * _id)
{
   if (strcmp (_id, UberCasino::GameDataReader::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::DataReader NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

UberCasino::GameDataReader_ptr UberCasino::GameDataReader::_narrow (DDS::Object_ptr p)
{
   UberCasino::GameDataReader_ptr result = NULL;
   if (p && p->_is_a (UberCasino::GameDataReader::_local_id))
   {
      result = dynamic_cast < UberCasino::GameDataReader_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

UberCasino::GameDataReader_ptr UberCasino::GameDataReader::_unchecked_narrow (DDS::Object_ptr p)
{
   UberCasino::GameDataReader_ptr result;
   result = dynamic_cast < UberCasino::GameDataReader_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * UberCasino::GameDataReaderView::_local_id = "IDL:UberCasino/GameDataReaderView:1.0";

UberCasino::GameDataReaderView_ptr UberCasino::GameDataReaderView::_duplicate (UberCasino::GameDataReaderView_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean UberCasino::GameDataReaderView::_local_is_a (const char * _id)
{
   if (strcmp (_id, UberCasino::GameDataReaderView::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::DataReaderView NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

UberCasino::GameDataReaderView_ptr UberCasino::GameDataReaderView::_narrow (DDS::Object_ptr p)
{
   UberCasino::GameDataReaderView_ptr result = NULL;
   if (p && p->_is_a (UberCasino::GameDataReaderView::_local_id))
   {
      result = dynamic_cast < UberCasino::GameDataReaderView_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

UberCasino::GameDataReaderView_ptr UberCasino::GameDataReaderView::_unchecked_narrow (DDS::Object_ptr p)
{
   UberCasino::GameDataReaderView_ptr result;
   result = dynamic_cast < UberCasino::GameDataReaderView_ptr> (p);
   if (result) result->m_count++;
   return result;
}



