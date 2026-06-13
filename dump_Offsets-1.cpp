// YuB-X Version: 2.1.6V
// Roblox Version: version-ae421f0582e54718
// Dump Time:      2026-03-22 23:32:26
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
        lua_State* thread;
        int32_t thread_ref;
        int32_t objectId;
    };

    struct WeakThreadRef
    {
        std::uint8_t pad_0[16];
        WeakThreadRef* previous;
        WeakThreadRef* next;
        LiveThreadRef* liveThreadRef;
        struct Node_t* node;
        std::uint8_t pad_1[8];
    };

    struct debugger_result_t {
        std::int32_t result;
        std::int32_t unk[0x4];
    };
}

namespace Offsets
{
    const uintptr_t Print                                = REBASE(0x1C8E7A0);

    const uintptr_t RawScheduler                         = REBASE(0x8287B48);
    const uintptr_t OpcodeLookupTable                    = REBASE(0x616d2c0);
    const uintptr_t AppdataInfo                          = REBASE(0x81D3B58);
    const uintptr_t LuaVMLoad                            = REBASE(0x1B05690);

    const uintptr_t FireMouseClick                       = REBASE(0x23FC370);
    const uintptr_t FireRightMouseClick                  = REBASE(0x23FC510);
    const uintptr_t FireMouseHoverEnter                  = REBASE(0x23FD910);
    const uintptr_t FireMouseHoverLeave                  = REBASE(0x23FDAB0);
    const uintptr_t IsLegalSendEvent                     = REBASE(0xA21DF0);

    const uintptr_t FireTouchInterest                    = REBASE(0x27E2AA0);
    const uintptr_t FireProximityPrompt                  = REBASE(0x24775D0);

    const uintptr_t TaskDefer                            = REBASE(0x1C74F00);
    const uintptr_t ScriptContextResume                  = REBASE(0x1BC2460);

    const uintptr_t GetLuaStateForInstance               = REBASE(0x1ADA240);
    const uintptr_t CastArgs                             = REBASE(0x1AE3110);

    const uintptr_t ConnectionDisconnect                 = REBASE(0x4697F20);

    namespace InstanceBridge {
        const uintptr_t Push                             = REBASE(0x1BCECA0);
    }

    namespace RobloxProperty {
        const uintptr_t GetRobloxPropertyData            = REBASE(0xC0DCB0);
        const uintptr_t KTable                           = REBASE(0x7AE34F0);
    }

    namespace RobloxThread {
        const uintptr_t IdentityPtr                      = REBASE(0x7C18348);
        const uintptr_t Impersonator                     = REBASE(0x4117130);
        const uintptr_t GetTlsPointer                    = REBASE(0x9320);
    }

    namespace Flags {
        const uintptr_t EnableLoadModule                 = REBASE(0x7B61808);
        const uintptr_t LockViolationInstanceCrash       = REBASE(0x7B592F8);
        const uintptr_t LockViolationScriptCrash         = REBASE(0x7B5A748);
        const uintptr_t WndProcessCheck                  = REBASE(0x6D90B18);
        const uintptr_t LuaStepIntervalMsOverrideEnabled = REBASE(0x7B5F8C8);
        const uintptr_t TaskSchedulerLimitTargetFpsTo240 = REBASE(0x7DAFB88);
        const uintptr_t SetFastFlag                      = REBASE(0x46ACBE0);
        const uintptr_t TaskSchedulerTargetFps           = REBASE(0x7AE3464);
    }

    namespace Luau {
        const uintptr_t Luau_Execute                     = REBASE(0x3DDF850);
        const uintptr_t LuaO_NilObject                   = REBASE(0x5C6B9D8);
        const uintptr_t LuaH_DummyNode                   = REBASE(0x5C6B0B8);
        const uintptr_t LuaC_Step                        = REBASE(0x3DD6790);
    }

    const uintptr_t LuaD_throw                           = REBASE(0x3DC71E0);
    const uintptr_t luaF_freeproto                       = REBASE(0x3E2DD10);
    const uintptr_t luaF_newproto                        = REBASE(0x3E2D830);
    const uintptr_t luaL_argerrorL                       = REBASE(0x3DCC290);
    const uintptr_t luaL_typeerrorL                      = REBASE(0x2625A40);
    const uintptr_t luaL_findtable                       = REBASE(0x3DD0690);
    const uintptr_t luaL_where                           = REBASE(0x3DCC430);
    const uintptr_t luaL_register                        = REBASE(0x3DCF7C0);
    const uintptr_t currfuncname                         = REBASE(0x3DCC210);
    const uintptr_t luaG_runerrorL                       = REBASE(0x3DD77E0);
    const uintptr_t luaO_pushvfstring                    = REBASE(0x3DC6340);
    const uintptr_t luaD_growstack                       = REBASE(0x3DC54E0);
    const uintptr_t luaD_rawrunprotected                 = REBASE(0x3DC71B0);
    const uintptr_t luaA_toobject                        = REBASE(0x3DC53A0);
    const uintptr_t lua_rawcheckstack                    = REBASE(0x3DC5800);
    const uintptr_t lua_pushvfstring                     = REBASE(0x3DC6340);
    const uintptr_t lua_xmove                            = REBASE(0x3CFA330);
    const uintptr_t pseudo2addr                          = REBASE(0x3DC52E0);
    const uintptr_t luaT_objtypename                     = REBASE(0x3E2D810);
    const uintptr_t auxopen                              = REBASE(0x3DFFBF0);
    const uintptr_t get_capabilites                      = REBASE(0x4117080);
    const uintptr_t LuaL_checktype                       = REBASE(0x1769BA0);
    const uintptr_t newpage                              = REBASE(0x3E1E580);
    const uintptr_t newclasspage                         = REBASE(0x3E1E630);
    const uintptr_t freeclasspage                        = REBASE(0x3E1E6A0);
    const uintptr_t newgcoblock                          = REBASE(0x3E1E7D0);
    const uintptr_t freeblock                            = REBASE(0x3E1E870);
    const uintptr_t luaM_free                            = REBASE(0x3E1E920);
    const uintptr_t luaM_freegco                         = REBASE(0x3E1E9A0);
    const uintptr_t luaM_visitgco                        = REBASE(0x3E1EAC0);
    const uintptr_t luaM_toobig                          = REBASE(0x3E1E550);

    const uintptr_t Register                             = REBASE(0x295ACD0);

    namespace Signal {
        constexpr uintptr_t next                         = 0x10;
        constexpr uintptr_t enabled                      = 0x20;
        constexpr uintptr_t signalSlot                   = 0x30;
        constexpr uintptr_t signalSlotWrapper            = 0x38;
        namespace SignalSlotWrapper {
            constexpr uintptr_t Ptr                      = 0x10;
            constexpr uintptr_t secondPtr                = 0x18;
            constexpr uintptr_t thirdPtr                 = 0x38;
        }
        namespace SignalSlot {
            constexpr uintptr_t isOnce                   = 0xB5;
            constexpr uintptr_t SignalRefs               = 0x70;
            namespace Refs {
                constexpr uintptr_t luaThread            = 0x8;
                constexpr uintptr_t luaThreadRefId       = 0x10;
                constexpr uintptr_t functionRefId        = 0x14;
            }
        }
        namespace WaitSlot {
            constexpr uintptr_t checkPointer             = 0x10;
            constexpr uintptr_t connectionRefs           = 0x38;
            constexpr uintptr_t connectionRefs2          = 0x40;
            constexpr uintptr_t connectionRefs3          = 0x50;
            constexpr uintptr_t threadRefContainer       = 0x18;
            constexpr uintptr_t threadRefContainer2      = 0x8;
            constexpr uintptr_t threadRefContainer3      = 0x10;
            constexpr uintptr_t threadRef                = 0x20;
        }
    }

    namespace Slot_wrapper {
        static auto weak_object_ref                      = 0x70;
        static auto function_id                          = 0x14;
        static auto thread_id                            = 0x10;
        static auto thread                               = 0x8;
    }

    namespace Connection {
        static auto next                                 = 0x10;
        static auto enabled                              = 0x20;
        static auto slot_wrapper                         = 0x30;
        static auto slot_wrapper_self                    = 0x38;
    }

    namespace DataModel {
        const uintptr_t LocalPlayer                      = 0x130;
        const uintptr_t Name                             = 0xB0;
        const uintptr_t PlaceId                          = 0x198;
        const uintptr_t GameLoaded                       = 0x600;
        const uintptr_t UserId                           = 0x2D8;
        const uintptr_t FakeDataModelToDataModel         = 0x1C0;
        const uintptr_t FakeDataModelPointer             = REBASE(0x81D3EA8);
    }

    namespace ScriptContext {
        const uintptr_t Face                             = 0x848;
        const uintptr_t RequireBypass                    = 0x930;
    }

    namespace BasePart {
        const uintptr_t Primitive                        = 0x148;
        namespace PrimitiveStructure {
            const uintptr_t Overlap                      = 0x200;
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
