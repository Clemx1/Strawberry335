/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "QuestDef.h"
#include "Player.h"
#include "Logon.h"

QuestTemplate::QuestTemplate(Field* questRecord)
{
    Id = questRecord[0].GetUInt32();
    Method = questRecord[1].GetUInt8();
    Level = questRecord[2].GetInt16();
    MinLevel = questRecord[3].GetUInt8();
    MaxLevel = questRecord[4].GetUInt8();
    ZoneOrSort = questRecord[5].GetInt16();
    Type = questRecord[6].GetUInt16();
    SuggestedPlayers = questRecord[7].GetUInt8();
    LimitTime = questRecord[8].GetUInt32();
    RequiredClasses = questRecord[9].GetUInt16();
    RequiredRaces = questRecord[10].GetUInt16();
    RequiredSkillId = questRecord[11].GetUInt16();
    RequiredSkillPoints = questRecord[12].GetUInt16();
    RequiredFactionId1 = questRecord[13].GetUInt16();
    RequiredFactionId2 = questRecord[14].GetUInt16();
    RequiredFactionValue1 = questRecord[15].GetInt32();
    RequiredFactionValue2 = questRecord[16].GetInt32();
    RequiredMinRepFaction = questRecord[17].GetUInt16();
    RequiredMaxRepFaction = questRecord[18].GetUInt16();
    RequiredMinRepValue = questRecord[19].GetInt32();
    RequiredMaxRepValue = questRecord[20].GetInt32();
    PrevQuestId = questRecord[21].GetInt32();
    NextQuestId = questRecord[22].GetInt32();
    ExclusiveGroup = questRecord[23].GetInt32();
    NextQuestIdChain = questRecord[24].GetUInt32();
    RewardXPId = questRecord[25].GetUInt8();
    RewardOrRequiredMoney = questRecord[26].GetInt32();
    RewardMoneyMaxLevel = questRecord[27].GetUInt32();
    RewardSpell = questRecord[28].GetUInt32();
    RewardSpellCast = questRecord[29].GetInt32();
    RewardHonor = questRecord[30].GetUInt32();
    RewardHonorMultiplier = questRecord[31].GetFloat();
    RewardMailTemplateId = questRecord[32].GetUInt32();
    RewardMailDelay = questRecord[33].GetUInt32();
    SourceItemId = questRecord[34].GetUInt32();
    SourceItemIdCount = questRecord[35].GetUInt8();
    SourceSpellid = questRecord[36].GetUInt32();
    Flags = questRecord[37].GetUInt32();
    uint32 SpecialFlags = questRecord[38].GetUInt8();
    RewardTitleId = questRecord[39].GetUInt8();
    RequiredPlayerKills = questRecord[40].GetUInt8();
    RewardTalents = questRecord[41].GetUInt8();
    RewardArenaPoints = questRecord[42].GetUInt16();

    for (int i = 0; i < QUEST_REWARDS_COUNT; ++i)
        RewardItemId[i] = questRecord[43+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARDS_COUNT; ++i)
        RewardItemIdCount[i] = questRecord[47+i].GetUInt16();

    for (int i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        RewardChoiceItemId[i] = questRecord[51+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        RewardChoiceItemCount[i] = questRecord[57+i].GetUInt16();

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        RewardFactionId[i] = questRecord[63+i].GetUInt16();

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        RewardFactionValueId[i] = questRecord[68+i].GetInt32();

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        RewardFactionValueIdOverride[i] = questRecord[73+i].GetInt32();

    PointMapId = questRecord[78].GetUInt16();
    PointX = questRecord[79].GetFloat();
    PointY = questRecord[80].GetFloat();
    PointOption = questRecord[81].GetUInt32();
    Title = questRecord[82].GetString();
    Objectives = questRecord[83].GetString();
    Details = questRecord[84].GetString();
    EndText = questRecord[85].GetString();
    OfferRewardText = questRecord[86].GetString();
    RequestItemsText = questRecord[87].GetString();
    CompletedText = questRecord[88].GetString();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        RequiredNpcOrGo[i] = questRecord[89+i].GetInt32();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        RequiredNpcOrGoCount[i] = questRecord[93+i].GetUInt16();

    for (int i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT; ++i)
        RequiredSourceItemId[i] = questRecord[97+i].GetUInt32();

    for (int i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT; ++i)
        RequiredSourceItemCount[i] = questRecord[101+i].GetUInt16();

    for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
        RequiredItemId[i] = questRecord[105+i].GetUInt32();

    for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
        RequiredItemCount[i] = questRecord[111+i].GetUInt16();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        RequiredSpellCast[i] = questRecord[117+i].GetUInt32();

    // int8 Unknown0 = questRecord[121].GetUInt8();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ObjectiveText[i] = questRecord[122+i].GetString();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        DetailsEmote[i] = questRecord[126+i].GetUInt16();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        DetailsEmoteDelay[i] = questRecord[130+i].GetUInt32();

    EmoteOnIncomplete = questRecord[134].GetUInt16();
    EmoteOnComplete = questRecord[135].GetUInt16();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        OfferRewardEmote[i] = questRecord[136+i].GetInt16();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        OfferRewardEmoteDelay[i] = questRecord[140+i].GetInt32();

    StartScript = questRecord[144].GetUInt32();
    CompleteScript = questRecord[145].GetUInt32();

    // int32 WDBVerified = questRecord[146].GetInt32();

    Flags |= SpecialFlags << 20;
    if (Flags & QUEST_TRINITY_FLAGS_AUTO_ACCEPT)
        Flags |= QUEST_FLAGS_AUTO_ACCEPT;

    m_reqitemscount = 0;
    m_reqCreatureOrGOcount = 0;
    m_rewitemscount = 0;
    m_rewchoiceitemscount = 0;

    for (int i=0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
        if (RequiredItemId[i])
            ++m_reqitemscount;

    for (int i=0; i < QUEST_OBJECTIVES_COUNT; ++i)
        if (RequiredNpcOrGo[i])
            ++m_reqCreatureOrGOcount;

    for (int i=0; i < QUEST_REWARDS_COUNT; ++i)
        if (RewardItemId[i])
            ++m_rewitemscount;

    for (int i=0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        if (RewardChoiceItemId[i])
            ++m_rewchoiceitemscount;
}

int32 QuestTemplate::GetRewOrReqMoney() const
{
    if (RewardOrRequiredMoney <= 0)
        return RewardOrRequiredMoney;

    return int32(RewardOrRequiredMoney); //* sWorld->getRate(RATE_DROP_MONEY));
}
