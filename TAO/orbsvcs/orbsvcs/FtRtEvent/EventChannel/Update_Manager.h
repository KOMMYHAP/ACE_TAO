// -*- C++ -*-

//=============================================================================
/**
 *  @file   Update_Manager.h
 *
 *  $Id$
 *
 *  @author Huang-Ming Huang <hh1@cse.wustl.edu>
 */
//=============================================================================

#ifndef UPDATE_MANAGER_H
#define UPDATE_MANAGER_H

#include "ace/Synch_T.h"
#include "Dynamic_Bitset.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

typedef Dynamic_Bitset bit_vector;

/**
 * @class Update_Manager
 *
 * @brief Manages the set_update() requests to the replicas for in AMI replication strategy. 
 *        Once the primary get the first n replies from the backup replicas and n >= 
 *        transaction_depth, it will signal the event specified in the constructor.
 */

class Update_Manager
{
public:
  Update_Manager(ACE_Auto_Event& evt,
    int num_backups,
    int transaction_depth,
    bool& success);
  ~Update_Manager();

  void handle_reply(int id);
  void handle_exception(int id);

private:
  ACE_Auto_Event& evt_; 
  bit_vector replied_;
  bit_vector signal_condition_;
  bit_vector suicide_condition_;
  int num_backups_;
  int transaction_level_;
  bool& success_;
  ACE_Thread_Mutex mutex_;
};

#endif
