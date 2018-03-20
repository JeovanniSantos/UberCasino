//******************************************************************
// 
//  Generated by IDL to C++ Translator
//  
//  File name: UberCasinoDcps.h
//  Source: UberCasinoDcps.idl
//  Generated: Mon Mar 19 22:20:31 2018
//  OpenSplice V6.4.140320OSS
//  
//******************************************************************
#ifndef _UBERCASINODCPS_H_
#define _UBERCASINODCPS_H_

#include "sacpp_mapping.h"
#include "sacpp_DDS_DCPS.h"
#include "dds_dcps.h"
#include "UberCasino.h"


namespace UberCasino
{

   class PlayerTypeSupportInterface;

   typedef PlayerTypeSupportInterface * PlayerTypeSupportInterface_ptr;
   typedef DDS_DCPSInterface_var < PlayerTypeSupportInterface> PlayerTypeSupportInterface_var;
   typedef DDS_DCPSInterface_out < PlayerTypeSupportInterface> PlayerTypeSupportInterface_out;


   class PlayerDataWriter;

   typedef PlayerDataWriter * PlayerDataWriter_ptr;
   typedef DDS_DCPSInterface_var < PlayerDataWriter> PlayerDataWriter_var;
   typedef DDS_DCPSInterface_out < PlayerDataWriter> PlayerDataWriter_out;


   class PlayerDataReader;

   typedef PlayerDataReader * PlayerDataReader_ptr;
   typedef DDS_DCPSInterface_var < PlayerDataReader> PlayerDataReader_var;
   typedef DDS_DCPSInterface_out < PlayerDataReader> PlayerDataReader_out;


   class PlayerDataReaderView;

   typedef PlayerDataReaderView * PlayerDataReaderView_ptr;
   typedef DDS_DCPSInterface_var < PlayerDataReaderView> PlayerDataReaderView_var;
   typedef DDS_DCPSInterface_out < PlayerDataReaderView> PlayerDataReaderView_out;


   class GameTypeSupportInterface;

   typedef GameTypeSupportInterface * GameTypeSupportInterface_ptr;
   typedef DDS_DCPSInterface_var < GameTypeSupportInterface> GameTypeSupportInterface_var;
   typedef DDS_DCPSInterface_out < GameTypeSupportInterface> GameTypeSupportInterface_out;


   class GameDataWriter;

   typedef GameDataWriter * GameDataWriter_ptr;
   typedef DDS_DCPSInterface_var < GameDataWriter> GameDataWriter_var;
   typedef DDS_DCPSInterface_out < GameDataWriter> GameDataWriter_out;


   class GameDataReader;

   typedef GameDataReader * GameDataReader_ptr;
   typedef DDS_DCPSInterface_var < GameDataReader> GameDataReader_var;
   typedef DDS_DCPSInterface_out < GameDataReader> GameDataReader_out;


   class GameDataReaderView;

   typedef GameDataReaderView * GameDataReaderView_ptr;
   typedef DDS_DCPSInterface_var < GameDataReaderView> GameDataReaderView_var;
   typedef DDS_DCPSInterface_out < GameDataReaderView> GameDataReaderView_out;

   struct PlayerSeq_uniq_ {};
   typedef DDS_DCPSUFLSeq < Player, struct PlayerSeq_uniq_> PlayerSeq;
   typedef DDS_DCPSSequence_var < PlayerSeq> PlayerSeq_var;
   typedef DDS_DCPSSequence_out < PlayerSeq> PlayerSeq_out;
   class PlayerTypeSupportInterface
   :
      virtual public DDS::TypeSupport
   { 
   public:
      typedef PlayerTypeSupportInterface_ptr _ptr_type;
      typedef PlayerTypeSupportInterface_var _var_type;

      static PlayerTypeSupportInterface_ptr _duplicate (PlayerTypeSupportInterface_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static PlayerTypeSupportInterface_ptr _narrow (DDS::Object_ptr obj);
      static PlayerTypeSupportInterface_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static PlayerTypeSupportInterface_ptr _nil () { return 0; }
      static const char * _local_id;
      PlayerTypeSupportInterface_ptr _this () { return this; }


   protected:
      PlayerTypeSupportInterface () {};
      ~PlayerTypeSupportInterface () {};
   private:
      PlayerTypeSupportInterface (const PlayerTypeSupportInterface &);
      PlayerTypeSupportInterface & operator = (const PlayerTypeSupportInterface &);
   };

   class PlayerDataWriter
   :
      virtual public DDS::DataWriter
   { 
   public:
      typedef PlayerDataWriter_ptr _ptr_type;
      typedef PlayerDataWriter_var _var_type;

      static PlayerDataWriter_ptr _duplicate (PlayerDataWriter_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static PlayerDataWriter_ptr _narrow (DDS::Object_ptr obj);
      static PlayerDataWriter_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static PlayerDataWriter_ptr _nil () { return 0; }
      static const char * _local_id;
      PlayerDataWriter_ptr _this () { return this; }

      virtual DDS::LongLong register_instance (const Player& instance_data) = 0;
      virtual DDS::LongLong register_instance_w_timestamp (const Player& instance_data, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long unregister_instance (const Player& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long unregister_instance_w_timestamp (const Player& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long write (const Player& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long write_w_timestamp (const Player& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long dispose (const Player& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long dispose_w_timestamp (const Player& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long writedispose (const Player& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long writedispose_w_timestamp (const Player& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long get_key_value (Player& key_holder, DDS::LongLong handle) = 0;
      virtual DDS::LongLong lookup_instance (const Player& instance_data) = 0;

   protected:
      PlayerDataWriter () {};
      ~PlayerDataWriter () {};
   private:
      PlayerDataWriter (const PlayerDataWriter &);
      PlayerDataWriter & operator = (const PlayerDataWriter &);
   };

   class PlayerDataReader
   :
      virtual public DDS::DataReader
   { 
   public:
      typedef PlayerDataReader_ptr _ptr_type;
      typedef PlayerDataReader_var _var_type;

      static PlayerDataReader_ptr _duplicate (PlayerDataReader_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static PlayerDataReader_ptr _narrow (DDS::Object_ptr obj);
      static PlayerDataReader_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static PlayerDataReader_ptr _nil () { return 0; }
      static const char * _local_id;
      PlayerDataReader_ptr _this () { return this; }

      virtual DDS::Long read (PlayerSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take (PlayerSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_w_condition (PlayerSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_w_condition (PlayerSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long read_next_sample (Player& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long take_next_sample (Player& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long read_instance (PlayerSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_instance (PlayerSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance (PlayerSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_next_instance (PlayerSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance_w_condition (PlayerSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_next_instance_w_condition (PlayerSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long return_loan (PlayerSeq& received_data, DDS::SampleInfoSeq& info_seq) = 0;
      virtual DDS::Long get_key_value (Player& key_holder, DDS::LongLong handle) = 0;
      virtual DDS::LongLong lookup_instance (const Player& instance) = 0;

   protected:
      PlayerDataReader () {};
      ~PlayerDataReader () {};
   private:
      PlayerDataReader (const PlayerDataReader &);
      PlayerDataReader & operator = (const PlayerDataReader &);
   };

   class PlayerDataReaderView
   :
      virtual public DDS::DataReaderView
   { 
   public:
      typedef PlayerDataReaderView_ptr _ptr_type;
      typedef PlayerDataReaderView_var _var_type;

      static PlayerDataReaderView_ptr _duplicate (PlayerDataReaderView_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static PlayerDataReaderView_ptr _narrow (DDS::Object_ptr obj);
      static PlayerDataReaderView_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static PlayerDataReaderView_ptr _nil () { return 0; }
      static const char * _local_id;
      PlayerDataReaderView_ptr _this () { return this; }

      virtual DDS::Long read (PlayerSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take (PlayerSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_w_condition (PlayerSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_w_condition (PlayerSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long read_next_sample (Player& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long take_next_sample (Player& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long read_instance (PlayerSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_instance (PlayerSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance (PlayerSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_next_instance (PlayerSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance_w_condition (PlayerSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_next_instance_w_condition (PlayerSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long return_loan (PlayerSeq& received_data, DDS::SampleInfoSeq& info_seq) = 0;
      virtual DDS::Long get_key_value (Player& key_holder, DDS::LongLong handle) = 0;
      virtual DDS::LongLong lookup_instance (const Player& instance) = 0;

   protected:
      PlayerDataReaderView () {};
      ~PlayerDataReaderView () {};
   private:
      PlayerDataReaderView (const PlayerDataReaderView &);
      PlayerDataReaderView & operator = (const PlayerDataReaderView &);
   };

   struct GameSeq_uniq_ {};
   typedef DDS_DCPSUFLSeq < Game, struct GameSeq_uniq_> GameSeq;
   typedef DDS_DCPSSequence_var < GameSeq> GameSeq_var;
   typedef DDS_DCPSSequence_out < GameSeq> GameSeq_out;
   class GameTypeSupportInterface
   :
      virtual public DDS::TypeSupport
   { 
   public:
      typedef GameTypeSupportInterface_ptr _ptr_type;
      typedef GameTypeSupportInterface_var _var_type;

      static GameTypeSupportInterface_ptr _duplicate (GameTypeSupportInterface_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static GameTypeSupportInterface_ptr _narrow (DDS::Object_ptr obj);
      static GameTypeSupportInterface_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static GameTypeSupportInterface_ptr _nil () { return 0; }
      static const char * _local_id;
      GameTypeSupportInterface_ptr _this () { return this; }


   protected:
      GameTypeSupportInterface () {};
      ~GameTypeSupportInterface () {};
   private:
      GameTypeSupportInterface (const GameTypeSupportInterface &);
      GameTypeSupportInterface & operator = (const GameTypeSupportInterface &);
   };

   class GameDataWriter
   :
      virtual public DDS::DataWriter
   { 
   public:
      typedef GameDataWriter_ptr _ptr_type;
      typedef GameDataWriter_var _var_type;

      static GameDataWriter_ptr _duplicate (GameDataWriter_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static GameDataWriter_ptr _narrow (DDS::Object_ptr obj);
      static GameDataWriter_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static GameDataWriter_ptr _nil () { return 0; }
      static const char * _local_id;
      GameDataWriter_ptr _this () { return this; }

      virtual DDS::LongLong register_instance (const Game& instance_data) = 0;
      virtual DDS::LongLong register_instance_w_timestamp (const Game& instance_data, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long unregister_instance (const Game& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long unregister_instance_w_timestamp (const Game& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long write (const Game& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long write_w_timestamp (const Game& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long dispose (const Game& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long dispose_w_timestamp (const Game& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long writedispose (const Game& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long writedispose_w_timestamp (const Game& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long get_key_value (Game& key_holder, DDS::LongLong handle) = 0;
      virtual DDS::LongLong lookup_instance (const Game& instance_data) = 0;

   protected:
      GameDataWriter () {};
      ~GameDataWriter () {};
   private:
      GameDataWriter (const GameDataWriter &);
      GameDataWriter & operator = (const GameDataWriter &);
   };

   class GameDataReader
   :
      virtual public DDS::DataReader
   { 
   public:
      typedef GameDataReader_ptr _ptr_type;
      typedef GameDataReader_var _var_type;

      static GameDataReader_ptr _duplicate (GameDataReader_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static GameDataReader_ptr _narrow (DDS::Object_ptr obj);
      static GameDataReader_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static GameDataReader_ptr _nil () { return 0; }
      static const char * _local_id;
      GameDataReader_ptr _this () { return this; }

      virtual DDS::Long read (GameSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take (GameSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_w_condition (GameSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_w_condition (GameSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long read_next_sample (Game& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long take_next_sample (Game& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long read_instance (GameSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_instance (GameSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance (GameSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_next_instance (GameSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance_w_condition (GameSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_next_instance_w_condition (GameSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long return_loan (GameSeq& received_data, DDS::SampleInfoSeq& info_seq) = 0;
      virtual DDS::Long get_key_value (Game& key_holder, DDS::LongLong handle) = 0;
      virtual DDS::LongLong lookup_instance (const Game& instance) = 0;

   protected:
      GameDataReader () {};
      ~GameDataReader () {};
   private:
      GameDataReader (const GameDataReader &);
      GameDataReader & operator = (const GameDataReader &);
   };

   class GameDataReaderView
   :
      virtual public DDS::DataReaderView
   { 
   public:
      typedef GameDataReaderView_ptr _ptr_type;
      typedef GameDataReaderView_var _var_type;

      static GameDataReaderView_ptr _duplicate (GameDataReaderView_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static GameDataReaderView_ptr _narrow (DDS::Object_ptr obj);
      static GameDataReaderView_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static GameDataReaderView_ptr _nil () { return 0; }
      static const char * _local_id;
      GameDataReaderView_ptr _this () { return this; }

      virtual DDS::Long read (GameSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take (GameSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_w_condition (GameSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_w_condition (GameSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long read_next_sample (Game& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long take_next_sample (Game& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long read_instance (GameSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_instance (GameSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance (GameSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_next_instance (GameSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance_w_condition (GameSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_next_instance_w_condition (GameSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long return_loan (GameSeq& received_data, DDS::SampleInfoSeq& info_seq) = 0;
      virtual DDS::Long get_key_value (Game& key_holder, DDS::LongLong handle) = 0;
      virtual DDS::LongLong lookup_instance (const Game& instance) = 0;

   protected:
      GameDataReaderView () {};
      ~GameDataReaderView () {};
   private:
      GameDataReaderView (const GameDataReaderView &);
      GameDataReaderView & operator = (const GameDataReaderView &);
   };

}




#endif 
