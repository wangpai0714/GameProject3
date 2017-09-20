﻿#ifndef _COMMON_WORK_THREAD_H_
#define _COMMON_WORK_THREAD_H_
#include "CommonThreadFunc.h"
#include "CommonMsgQueue.h"
#include "IBufferHandler.h"
#include "LockFreeQueue.h"

Th_RetName _CommonWorkThread( void* pParam );

class CCommonWorkThread
{
public:
	CCommonWorkThread();

	~CCommonWorkThread();

	BOOL			Start();

	BOOL			Stop();

	void			Run();

	BOOL			ProcessTimeEvent();

	BOOL			ProcessMessage();

	BOOL			AddMessage(NetPacket* pNetPacket);

	BOOL			SetCommandHandler(IThreadCommandHandler* pCommandHandler);

	BOOL			OnThreadBegin();

	BOOL			OnThreadEnd();

protected:
	THANDLE					m_hThread;

	BOOL					m_bRun;

	IThreadCommandHandler*	m_pCommandHandler;

	ArrayLockFreeQueue<NetPacket*>   m_PacketQueue;

	UINT32					m_dwLastTick;


};

#endif //_COMMON_WORK_THREAD_H_
