#pragma once
#include "../Feature.h"

class CTickshiftHandler
{
	// logic
	void Recharge(CUserCmd* pCmd, CBaseEntity* pLocal);
	void Teleport(CUserCmd* pCmd);
	void Doubletap(const CUserCmd* pCmd, CBaseEntity* pLocal);
	void Speedhack(CUserCmd* pCmd);
	bool ValidWeapon(CBaseCombatWeapon* pWeapon);

	// utils
	void CLMoveFunc(float accumulated_extra_samples, bool bFinalTick);

	void MovePre(CBaseEntity* pLocal);
	void MoveMain(float accumulated_extra_samples, bool bFinalTick);

	bool bSpeedhack = false;
	bool bGoalReached = true;

public:
	int GetTicks(CBaseEntity* pLocal);
	void Run(float accumulated_extra_samples, bool bFinalTick, CBaseEntity* pLocal);
	void MovePost(CBaseEntity* pLocal, CUserCmd* pCmd);
	void Reset();

	int iDeficit = 0;
};

ADD_FEATURE(CTickshiftHandler, Ticks)