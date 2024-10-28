#pragma once

#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/PlayerSpawnParams.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/CharacterCustomizationState.hpp>
#include <RED4ext/Scripting/Natives/worldWorldID.hpp>
#include <cstdint>

namespace RED4ext
{
namespace game
{
struct MainQuestData
{
    ResourcePath questPath;    // 00
    bool questPathValid;       // 08
    CName additionalContentId; // 10
};

RED4EXT_ASSERT_SIZE(MainQuestData, 0x18);
RED4EXT_ASSERT_OFFSET(MainQuestData, questPath, 0x0);
RED4EXT_ASSERT_OFFSET(MainQuestData, questPathValid, 0x8);
RED4EXT_ASSERT_OFFSET(MainQuestData, additionalContentId, 0x10);

struct GameSessionDesc
{
    static constexpr const char* NAME = "gameGameSessionDesc";
    static constexpr const char* ALIAS = NAME;

    world::WorldID worldId; // 0

    bool unk38;     // 38
    uint32_t unk3C; // 3C
    uint32_t unk40; // 40
    uint32_t unk44; // 44

    bool unk48; // 48

    uint32_t unk4C; // 4C
    uint64_t unk50; // 50
    uint64_t unk58; // 58
    uint64_t unk60; // 60
    uint32_t unk68; // 68

    CString saveName; // 70 - QuickSave-1
    CString unk90;    // 90
    CString unkB0;    // B0

    std::uint64_t unkD0; // D0
    std::uint64_t unkD8; // D8

    PlayerSpawnParams playerSpawnParams; // E0

    uint64_t unk150; // 150
    uint64_t unk158; // 158

    DynArray<MainQuestData> mainQuests; // 160
    DynArray<MainQuestData> unk170;     // 170 - Empty on new game start, as far as I can tell

    std::uint64_t unk180; // 180
    std::uint64_t unk188; // 188
    std::uint64_t unk190; // 190

    Handle<game::ui::CharacterCustomizationState> characterCustomizationState; // 198

    bool unk1A8; // 1A8
    bool unk1A9; // 1A9
    bool unk1AA; // 1AA
    bool unk1AB; // 1AB

    CString saveMetadataRelativePath; // 1B0 - QuickSave-1/metadata.9.json
};
RED4EXT_ASSERT_SIZE(GameSessionDesc, 0x1D0);
RED4EXT_ASSERT_OFFSET(GameSessionDesc, worldId, 0x0);
RED4EXT_ASSERT_OFFSET(GameSessionDesc, unk58, 0x58);
RED4EXT_ASSERT_OFFSET(GameSessionDesc, unk60, 0x60);
RED4EXT_ASSERT_OFFSET(GameSessionDesc, saveName, 0x70);
RED4EXT_ASSERT_OFFSET(GameSessionDesc, unk90, 0x90);
RED4EXT_ASSERT_OFFSET(GameSessionDesc, unkB0, 0xB0);
RED4EXT_ASSERT_OFFSET(GameSessionDesc, unkD0, 0xD0);
RED4EXT_ASSERT_OFFSET(GameSessionDesc, unkD8, 0xD8);
RED4EXT_ASSERT_OFFSET(GameSessionDesc, playerSpawnParams, 0xE0);
RED4EXT_ASSERT_OFFSET(GameSessionDesc, mainQuests, 0x160);
RED4EXT_ASSERT_OFFSET(GameSessionDesc, unk170, 0x170);
RED4EXT_ASSERT_OFFSET(GameSessionDesc, characterCustomizationState, 0x198);
RED4EXT_ASSERT_OFFSET(GameSessionDesc, saveMetadataRelativePath, 0x1B0);

} // namespace game
using gameGameSessionDesc = game::GameSessionDesc;
} // namespace RED4ext