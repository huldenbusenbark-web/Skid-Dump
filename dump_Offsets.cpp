// YuB-X Version: 2.1.7V
// Roblox Version: version-6776addb8fbc4d17
// Dump Time:      2026-03-26 01:32:43
#pragma once

#include <cstdint>
#include <Windows.h>
#include <memory>
#include <string>

struct lua_State;

#define REBASE(Address) (Address + reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr)))

typedef enum { SUCCESS, YIELD, ERR } CoroutineResult;

namespace RBX
{
    struct LiveThreadRef {
        int _Refs;
        char Pad0[0x20];
        lua_State* thread;
        int32_t thread_ref;
        int32_t objectId;
    };

    struct debugger_result_t {
        std::int32_t result;
        std::int32_t unk[0x4];
    };
}

namespace Offsets
{
    const uintptr_t Print                                = REBASE(0x1CD0600);

    const uintptr_t RawScheduler                         = REBASE(0x7A08710);
    const uintptr_t OpcodeLookupTable                    = REBASE(0x61ed730);
    const uintptr_t AppdataInfo                          = REBASE(0x7959D88);
    const uintptr_t LuaVMLoad                            = REBASE(0x1B4D900);

    const uintptr_t FireMouseClick                       = REBASE(0x244F7F0);
    const uintptr_t FireRightMouseClick                  = REBASE(0x244F990);
    const uintptr_t FireMouseHoverEnter                  = REBASE(0x2450D90);
    const uintptr_t FireMouseHoverLeave                  = REBASE(0x2450F30);
    const uintptr_t IsLegalSendEvent                     = REBASE(0xA25AD0);

    const uintptr_t FireTouchInterest                    = REBASE(0x28407A0); 
    const uintptr_t FireProximityPrompt                  = REBASE(0x24CD7A0);

    const uintptr_t TaskDefer                            = REBASE(0x1CB7290);
    const uintptr_t ScriptContextResume                  = REBASE(0x1C02930);

    const uintptr_t GetLuaStateForInstance               = REBASE(0x1B19950);
    const uintptr_t CastArgs                             = REBASE(0x1B21BD0);

    const uintptr_t ConnectionDisconnect                 = REBASE(0x4723470);

    namespace InstanceBridge {
        const uintptr_t Push                             = REBASE(0x1C0E690);
    }

    namespace RobloxProperty {
        const uintptr_t GetRobloxPropertyData            = REBASE(0xC144E0);
        const uintptr_t KTable                           = REBASE(0x7269480);
    }

    namespace RobloxThread {
        const uintptr_t IdentityPtr                      = REBASE(0x73A2438);
        const uintptr_t Impersonator                     = REBASE(0x41F36E0);
        const uintptr_t GetTlsPointer                    = REBASE(0x8070);
    }

    namespace Flags {
        const uintptr_t EnableLoadModule                 = REBASE(0x72E9138);
        const uintptr_t LockViolationInstanceCrash       = REBASE(0x72DFA48);
        const uintptr_t LockViolationScriptCrash         = REBASE(0x72E10B8);
        const uintptr_t WndProcessCheck                  = REBASE(0x6E13718);
        const uintptr_t LuaStepIntervalMsOverrideEnabled = REBASE(0x72E70C8);
        //const uintptr_t TaskSchedulerLimitTargetFpsTo240 = REBASE(0xFFFF8008119B0000); // dont exits
        const uintptr_t SetFastFlag                      = REBASE(0x4738930);
        const uintptr_t TaskSchedulerTargetFps           = REBASE(0x7269378);
    }

    namespace Luau {
        const uintptr_t Luau_Execute                     = REBASE(0x4114200);
        const uintptr_t LuaO_NilObject                   = REBASE(0x5CF4668);
        const uintptr_t LuaH_DummyNode                   = REBASE(0x5CF3D48);
        const uintptr_t LuaC_Step                        = REBASE(0x410AF30);
    }

    const uintptr_t LuaD_throw                           = REBASE(0x40FB470);
    const uintptr_t luaF_freeproto                       = REBASE(0x4162CA0);
    const uintptr_t luaF_newproto                        = REBASE(0x41627C0);
    const uintptr_t luaL_argerrorL                       = REBASE(0x41005A0);
    const uintptr_t luaL_typeerrorL                      = REBASE(0x268A720);
    const uintptr_t luaL_findtable                       = REBASE(0x4104A30);
    const uintptr_t luaL_where                           = REBASE(0x4100740);
    const uintptr_t luaL_register                        = REBASE(0x4103B40);
    const uintptr_t currfuncname                         = REBASE(0x4100520);
    const uintptr_t luaG_runerrorL                       = REBASE(0x410BFA0);
    const uintptr_t luaO_pushvfstring                    = REBASE(0x40FA5D0);
    const uintptr_t luaD_growstack                       = REBASE(0x40F9760);
    const uintptr_t luaD_rawrunprotected                 = REBASE(0x40FB440);
    const uintptr_t luaA_toobject                        = REBASE(0x40F9620);
    const uintptr_t lua_rawcheckstack                    = REBASE(0x40F9A80);
    const uintptr_t lua_pushvfstring                     = REBASE(0x40FA5D0);
    const uintptr_t lua_xmove                            = REBASE(0x3DD1470);
    const uintptr_t pseudo2addr                          = REBASE(0x40F9560);
    const uintptr_t luaT_objtypename                     = REBASE(0x41627A0);
    const uintptr_t auxopen                              = REBASE(0x4134920);
    const uintptr_t get_capabilites                      = REBASE(0x41F3620);
    const uintptr_t LuaL_checktype                       = REBASE(0x3D2D640);
    const uintptr_t newpage                              = REBASE(0x41534D0);
    const uintptr_t newclasspage                         = REBASE(0x4153580);
    const uintptr_t freeclasspage                        = REBASE(0x41535F0);
    const uintptr_t newgcoblock                          = REBASE(0x4153690);
    const uintptr_t freeblock                            = REBASE(0x41537D0);
    const uintptr_t luaM_free                            = REBASE(0x4153890);
    const uintptr_t luaM_freegco                         = REBASE(0x4153910);
    const uintptr_t luaM_visitgco                        = REBASE(0x4153A30);
    const uintptr_t luaM_toobig                          = REBASE(0x41534A0);

    const uintptr_t Register                             = REBASE(0x29BAF00);

    namespace Signal {
        constexpr uintptr_t next = 0x10;
        constexpr uintptr_t enabled = 0x20;
        constexpr uintptr_t signalSlot = 0x30;
        constexpr uintptr_t signalSlotWrapper = 0x38;

        namespace SignalSlotWrapper {
            constexpr uintptr_t Ptr = 0x10;
            constexpr uintptr_t secondPtr = 0x18;
            constexpr uintptr_t thirdPtr = 0x38;
        }

        namespace SignalSlot {
            constexpr uintptr_t isOnce = 0xB5; 

            namespace Refs {
                constexpr uintptr_t luaThreadRefId = 0x30;
                constexpr uintptr_t functionRefId = 0x34;
            }
        }

        namespace WaitSlot {
            constexpr uintptr_t checkPointer = 0x10;
        }
    }

    namespace Slot_wrapper {
        constexpr uintptr_t weak_object_ref = 0x60;
        constexpr uintptr_t thread = 0x28;
    }

    namespace Connection {
        constexpr uintptr_t next = 0x10;
        constexpr uintptr_t enabled = 0x20;
        constexpr uintptr_t slot_wrapper = 0x30;
        constexpr uintptr_t slot_wrapper_self = 0x38;
    }


    namespace DataModel {
        const uintptr_t LocalPlayer                      = 0x130;
        const uintptr_t Name                             = 0xB0;
        const uintptr_t PlaceId                          = 0x198;
        const uintptr_t GameLoaded                       = 0x600;
        const uintptr_t UserId                           = 0x2D8;
        const uintptr_t FakeDataModelToDataModel         = 0x1C0;
        const uintptr_t FakeDataModelPointer             = REBASE(0x795A0D8);
    }

    namespace ScriptContext {
        const uintptr_t Face                             = 0x7F0;
        const uintptr_t RequireBypass                    = 0x8FD;
    }

    namespace BasePart {
        const uintptr_t Primitive                        = 0x148;
        namespace PrimitiveStructure {
            const uintptr_t Overlap                      = 0x1E8;
        }
    }
}

namespace Roblox
{
    inline auto Print = (uintptr_t(__fastcall*)(int, const char*, ...))Offsets::Print;

    inline auto TaskDefer = (int(__fastcall*)(lua_State*))Offsets::TaskDefer;
    inline auto Luau_Execute = (void(__fastcall*)(lua_State*))Offsets::Luau::Luau_Execute;
    inline auto GetTlsPointer = (void*(__fastcall*)(uintptr_t identityData))Offsets::RobloxThread::GetTlsPointer;
    inline auto GetLuaStateForInstance = (lua_State*(__fastcall*)(uint64_t, uint64_t*, uint64_t*))Offsets::GetLuaStateForInstance;

    inline auto GetRobloxPropertyData = (void*(__fastcall*)(uintptr_t, uintptr_t*, uintptr_t*, int))Offsets::RobloxProperty::GetRobloxPropertyData;
    inline auto KTable = reinterpret_cast<uintptr_t*>(Offsets::RobloxProperty::KTable);

    namespace InstanceBridge {
        inline auto UintPtr = (void(__fastcall*)(lua_State*, std::uintptr_t))Offsets::InstanceBridge::Push;
        inline auto Shared  = (void(__fastcall*)(lua_State*, std::shared_ptr<std::uintptr_t*>))Offsets::InstanceBridge::Push;
        inline auto Void    = (void(__fastcall*)(lua_State*, void**))Offsets::InstanceBridge::Push;
        inline auto Void2   = (void(__fastcall*)(lua_State*, void*))Offsets::InstanceBridge::Push;
        inline auto Weak    = (void(__fastcall*)(lua_State*, std::weak_ptr<std::uintptr_t>))Offsets::InstanceBridge::Push;
    }

    inline auto LuaVM_Load  = (int32_t(__fastcall*)(lua_State*, std::string*, const char*, int32_t))Offsets::LuaVMLoad;
    inline auto CastArgs    = (uintptr_t(__fastcall*)(lua_State*, int, void*, bool, int))Offsets::CastArgs;
    inline auto isLegalSendEvent = (bool(__fastcall*)(uintptr_t*, uintptr_t*, uintptr_t))Offsets::IsLegalSendEvent;
    inline auto DisconnectConnection = (void(__fastcall*)(uintptr_t*))Offsets::ConnectionDisconnect;

    namespace Signals {
        inline auto FireProximityPrompt  = (uintptr_t*(__thiscall*)(uintptr_t))Offsets::FireProximityPrompt;
        inline auto FireMouseClick       = (void(__fastcall*)(__int64, float, __int64))Offsets::FireMouseClick;
        inline auto FireRightMouseClick  = (void(__fastcall*)(__int64, float, __int64))Offsets::FireRightMouseClick;
        inline auto FireMouseHoverEnter  = (void(__fastcall*)(__int64, __int64))Offsets::FireMouseHoverEnter;
        inline auto FireMouseHoverLeave  = (void(__fastcall*)(__int64, __int64))Offsets::FireMouseHoverLeave;
        inline auto FireTouchInterest    = (void(__fastcall*)(uintptr_t, uintptr_t, uintptr_t, bool, bool))Offsets::FireTouchInterest;
    }

    inline auto SCResume = (int(__fastcall*)(uintptr_t scriptContext, RBX::debugger_result_t*,
        RBX::LiveThreadRef**, int32_t nRet, bool isError,
        char const* errorMessage))Offsets::ScriptContextResume;
}
