// this is absolutely abhorrent but it's the only way I've found to get this to work

#define DIRTYSETADDRFUNCTION(ptr, funcName) void __declspec(naked) funcName() { __asm { mov eax, ptr } }
#define DIRTYSETADDR(funcName, addr) *(uint32_t*)(GetAddressFromMoveEAXFunction((uint32_t)&funcName)) = addr;

namespace DirtyAddressSetter
{
	uint32_t GetAddressFromMoveEAXFunction(uint32_t Function)
	{
		return *(uint32_t*)(Function + 1);
	}
	DIRTYSETADDRFUNCTION(CWorld::PlayerInFocus, PlayerInFocus)
	DIRTYSETADDRFUNCTION(CRadar::m_radarRange, RadarRange)
	DIRTYSETADDRFUNCTION(CPools::ms_pBuildingPool, BuildingPool)
	DIRTYSETADDRFUNCTION(CPools::ms_pObjectPool, ObjectPool)
	DIRTYSETADDRFUNCTION(CPools::ms_pPedPool, PedPool)
	DIRTYSETADDRFUNCTION(CPools::ms_pVehiclePool, VehiclePool)
	DIRTYSETADDRFUNCTION(CPools::ms_pCameraPool, CameraPool)
	DIRTYSETADDRFUNCTION(CTimer::m_CodePause, m_CodePause)
	DIRTYSETADDRFUNCTION(CTimer::m_UserPause, m_UserPause)
	DIRTYSETADDRFUNCTION(CTimer::m_FrameCounter, m_FrameCounter)
	DIRTYSETADDRFUNCTION(CTimer::m_snTimeInMilliseconds, m_snTimeInMilliseconds)
	DIRTYSETADDRFUNCTION(CTimer::ms_fMinTimeStep, ms_fMinTimeStep)
	DIRTYSETADDRFUNCTION(CTimer::ms_fMaxTimeStep, ms_fMaxTimeStep)
	DIRTYSETADDRFUNCTION(CTimer::ms_fTimeStep, ms_fTimeStep)
	DIRTYSETADDRFUNCTION(CTimer::ms_fTimeStepNonClipped, ms_fTimeStepNonClipped)
	DIRTYSETADDRFUNCTION(CTimer::ms_fTimeScale, ms_fTimeScale)
	DIRTYSETADDRFUNCTION(CTimer::ms_fTimeScale2, ms_fTimeScale2)
	DIRTYSETADDRFUNCTION(CTimer::ms_fTimeScale3, ms_fTimeScale3)
	DIRTYSETADDRFUNCTION(CStreaming::ms_disableStreaming, ms_disableStreaming)
	DIRTYSETADDRFUNCTION(CVisibilityPlugins::m_pedLodDistanceHigh, m_pedLodDistanceHigh)
	DIRTYSETADDRFUNCTION(CVisibilityPlugins::m_pedInCarLodDistanceHigh, m_pedInCarLodDistanceHigh)
	DIRTYSETADDRFUNCTION(CVisibilityPlugins::m_pedLodDistanceMed, m_pedLodDistanceMed)
	DIRTYSETADDRFUNCTION(CVisibilityPlugins::m_pedLodDistanceLow, m_pedLodDistanceLow)
	DIRTYSETADDRFUNCTION(CVisibilityPlugins::m_pedLodDistanceVlow, m_pedLodDistanceVlow)
	DIRTYSETADDRFUNCTION(CVisibilityPlugins::m_pedLodDistanceSlod, m_pedLodDistanceSlod)
	DIRTYSETADDRFUNCTION(CVisibilityPlugins::m_carLodDistanceHigh, m_carLodDistanceHigh)
	DIRTYSETADDRFUNCTION(CVisibilityPlugins::m_carLodDistanceMed, m_carLodDistanceMed)
	DIRTYSETADDRFUNCTION(CNetwork::m_bNetworkSession, m_bNetworkSession)
	DIRTYSETADDRFUNCTION(CNetwork::m_nNetworkStatus, m_nNetworkStatus)
	DIRTYSETADDRFUNCTION(CClock::ms_nGameClockForcedMinutes, ms_nGameClockForcedMinutes)
	DIRTYSETADDRFUNCTION(CClock::ms_nGameClockForcedHours, ms_nGameClockForcedHours)
	DIRTYSETADDRFUNCTION(CClock::CurrentDay, CurrentDay)
	DIRTYSETADDRFUNCTION(CClock::ms_nGameClockSeconds, ms_nGameClockSeconds)
	DIRTYSETADDRFUNCTION(CClock::ms_nGameClockMinutes, ms_nGameClockMinutes)
	DIRTYSETADDRFUNCTION(CClock::ms_nGameClockHours, ms_nGameClockHours)
	DIRTYSETADDRFUNCTION(CClock::ms_nGameClockDays, ms_nGameClockDays)
	DIRTYSETADDRFUNCTION(CClock::ms_nGameClockMonth, ms_nGameClockMonth)
	DIRTYSETADDRFUNCTION(CClock::ms_nMillisecondsPerGameMinute, ms_nMillisecondsPerGameMinute)
	void SetAll()
	{
		DIRTYSETADDR(PlayerInFocus, Addresses::nPlayerInFocus)
		DIRTYSETADDR(RadarRange, Addresses::nm_radarRange)
		DIRTYSETADDR(BuildingPool, Addresses::nms_pBuildingPool)
		DIRTYSETADDR(ObjectPool, Addresses::nms_pObjectPool)
		DIRTYSETADDR(PedPool, Addresses::nms_pPedPool)
		DIRTYSETADDR(VehiclePool, Addresses::nms_pVehiclePool)
		DIRTYSETADDR(CameraPool, Addresses::nms_pCameraPool)
		DIRTYSETADDR(m_CodePause, Addresses::nm_CodePause)
		DIRTYSETADDR(m_UserPause, Addresses::nm_UserPause)
		DIRTYSETADDR(m_FrameCounter, Addresses::nm_FrameCounter)
		DIRTYSETADDR(m_snTimeInMilliseconds, Addresses::nm_snTimeInMilliseconds)
		DIRTYSETADDR(ms_fMinTimeStep, Addresses::nms_fMinTimeStep)
		DIRTYSETADDR(ms_fMaxTimeStep, Addresses::nms_fMaxTimeStep)
		DIRTYSETADDR(ms_fTimeStep, Addresses::nms_fTimeStep)
		DIRTYSETADDR(ms_fTimeStepNonClipped, Addresses::nms_fTimeStepNonClipped)
		DIRTYSETADDR(ms_fTimeScale, Addresses::nms_fTimeScale)
		DIRTYSETADDR(ms_fTimeScale2, Addresses::nms_fTimeScale2)
		DIRTYSETADDR(ms_fTimeScale3, Addresses::nms_fTimeScale3)
		DIRTYSETADDR(ms_disableStreaming, Addresses::nms_disableStreaming)
		DIRTYSETADDR(m_pedLodDistanceHigh, Addresses::nm_pedLodDistanceHigh)
		DIRTYSETADDR(m_pedInCarLodDistanceHigh, Addresses::nm_pedInCarLodDistanceHigh)
		DIRTYSETADDR(m_pedLodDistanceMed, Addresses::nm_pedLodDistanceMed)
		DIRTYSETADDR(m_pedLodDistanceLow, Addresses::nm_pedLodDistanceLow)
		DIRTYSETADDR(m_pedLodDistanceVlow, Addresses::nm_pedLodDistanceVlow)
		DIRTYSETADDR(m_pedLodDistanceSlod, Addresses::nm_pedLodDistanceSlod)
		DIRTYSETADDR(m_carLodDistanceHigh, Addresses::nm_carLodDistanceHigh)
		DIRTYSETADDR(m_carLodDistanceMed, Addresses::nm_carLodDistanceMed)
		DIRTYSETADDR(m_bNetworkSession, Addresses::nm_bNetworkSession)
		DIRTYSETADDR(m_nNetworkStatus, Addresses::nm_nNetworkStatus)
		DIRTYSETADDR(ms_nGameClockForcedMinutes, Addresses::nms_nGameClockForcedMinutes)
		DIRTYSETADDR(ms_nGameClockForcedHours, Addresses::nms_nGameClockForcedHours)
		DIRTYSETADDR(CurrentDay, Addresses::nCurrentDay)
		DIRTYSETADDR(ms_nGameClockSeconds, Addresses::nms_nGameClockSeconds)
		DIRTYSETADDR(ms_nGameClockMinutes, Addresses::nms_nGameClockMinutes)
		DIRTYSETADDR(ms_nGameClockHours, Addresses::nms_nGameClockHours)
		DIRTYSETADDR(ms_nGameClockDays, Addresses::nms_nGameClockDays)
		DIRTYSETADDR(ms_nGameClockMonth, Addresses::nms_nGameClockMonth)
		DIRTYSETADDR(ms_nMillisecondsPerGameMinute, Addresses::nms_nMillisecondsPerGameMinute)
	}
}