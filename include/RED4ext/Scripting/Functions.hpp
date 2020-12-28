#pragma once

#include <cstdint>

#include <RED4ext/CName.hpp>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/CProperty.hpp>

namespace RED4ext
{
struct CClass;
struct CStack;

struct IFunction
{
    virtual void sub_0() = 0;
    virtual ~IFunction() = 0;

    virtual CClass* GetParent() = 0;
    virtual uint32_t GetFuncIndex() = 0;
    virtual void sub_20() = 0;
};

RED4EXT_ASSERT_SIZE(IFunction, 0x8);

struct CBaseFunction : IFunction
{
    bool Execute(CStack* aStack);

    CName name;
    CName name2;
    CProperty* returnType;
    int64_t unk20;
    DynArray<CProperty*> params;
    DynArray<CProperty*> localVars;
    int8_t unk48[0x30];
    uint32_t flags;
    uint32_t unk7C;
};

RED4EXT_ASSERT_SIZE(CBaseFunction, 0x80);
RED4EXT_ASSERT_OFFSET(CBaseFunction, name, 0x8);
RED4EXT_ASSERT_OFFSET(CBaseFunction, flags, 0x78);

struct CGlobalFunction : CBaseFunction
{
    uint32_t index; // The registration index.
};

RED4EXT_ASSERT_SIZE(CGlobalFunction, 0x88);
RED4EXT_ASSERT_OFFSET(CGlobalFunction, index, 0x80);

struct CClassFunction : CBaseFunction
{
    CClass* parent;
    uint32_t index; // The registration index.
};

RED4EXT_ASSERT_SIZE(CClassFunction, 0x90);
RED4EXT_ASSERT_OFFSET(CClassFunction, parent, 0x80);
RED4EXT_ASSERT_OFFSET(CClassFunction, index, 0x88);

struct CScriptedFunction : CBaseFunction
{
    CClass* parent;
};

RED4EXT_ASSERT_SIZE(CScriptedFunction, 0x88);
RED4EXT_ASSERT_OFFSET(CScriptedFunction, parent, 0x80);
} // namespace RED4ext

#ifdef RED4EXT_HEADER_ONLY
#include <RED4ext/Scripting/Functions-impl.hpp>
#endif