﻿#ifndef GAME_SHARD_GAME_DEF_H
#define GAME_SHARD_GAME_DEF_H

#include <nel/misc/types_nl.h>

#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif

typedef	uint32   UID;
typedef	uint32   RPC_SESSION;           ///  远程调用session
typedef uint32   TEMPLATE_ID;           ///  配置表使用的ID
typedef uint32   TEMPLATE_TYPE;         ///  

typedef uint32   CHECK_SUM;
typedef uint32   ERROR_TYPE;
typedef uint32   SCRIPT_ID;
typedef uint32   EVENT_ID;
typedef uint32   ACK_IDX;


#define RANDOM_SHOP_GRID_NUM        3
#define PLAYERNAME_LENGTH           (24)                ///  玩家名字最大长度
#define PLAYERNAME_LENGTH_MIN       (4)                 ///  玩家名字最小长度
#define RPC_SESSION_TCP_FLAG        0x80000000          ///  rpc_session协议标识，用于区分 tcp 和 udp协议。
#define FLOAT_RATE                  10000               ///  万分比
#define FRIEND_FIGHT_NUM            5
#define BAD_CHECK_SUM               CHECK_SUM(-1)

#define NEW_PLAYER_FRIEND_LEVEL     5
#define NEW_PLAYER_FIGHT_LEVEL      4

#define ONE_YEAR 60*60*24*365
#define ONE_DAY  60*60*24

///   flag(1) session(24)  sid(7)
///   flag   是tcp还是udp， 1:TCP  0:UDP
inline bool IsTCPSession( RPC_SESSION rpc_session ) {  return rpc_session&RPC_SESSION_TCP_FLAG;  }

#define PROP( type , name )\
	private:\
		type m_##name;\
	public:\
		inline void Set##name(type v){ \
			m_##name = v;\
		}\
		inline type Get##name(){\
			return m_##name;\
		}\

#define SAFE_DELETE( ptr ) do{ if( NULL != ptr ){ delete ptr ; ptr = NULL; } } while(0)
#define SAFE_DELETE_ARRAY( ptr ) do{ if( NULL != ptr ){ delete[] ptr; ptr = NULL; } } while(0)

#define GET_DBMSG(structname) \
    if( !data ) \
    return; \
    structname* db_msg = (structname*)( data ); \
    if( !db_msg ) \
    return ;

#define GET_WORKER_AND_STMT(__THREAD,__DB,__STMT) \
nl::sql_worker* pWorker = SelectThread(__THREAD).get_worker( __DB );\
if ( NULL == pWorker ){  return ; }\
nl::sql_stmt*   pStmt = pWorker->get_stmt( __STMT );\
if( NULL == pStmt ){ return; }

#define GET_WORKER_AND_STMT_MAIN(__THREAD,__DB,__STMT) \
    nl::sql_worker* pWorker = SelectThread(__THREAD).get_worker( __DB, true );\
    if ( NULL == pWorker ){  nlstop; }\
    nl::sql_stmt*   pStmt = pWorker->get_stmt( __STMT );\
    if( NULL == pStmt ){ nlstop; }\
    nl::sql_result* pResult = NULL;

#endif      //  GAME_SHARD_GAME_DEF_H
