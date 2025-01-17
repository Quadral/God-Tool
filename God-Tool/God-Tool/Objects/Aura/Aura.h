#pragma once
#include "../../Common/SharedDefines.h"
#include "../../Database/DatabaseManager.h"
#include "../../Common/Offsets.h"

class Aura
{
public:
    Aura(AuraRec& p_Rec) : m_AuraRec(p_Rec)
    {
        sDatabaseMgr->GetDatabaseByIndex(Spell)->GetSpellRow(p_Rec.SpellId, m_SpellEntry);
    }

    Aura() {}

    ~Aura() {}

public:
    AuraRec& GetAura()
    {
        return m_AuraRec;
    }

    SpellEntryRec& GetSpell()
    {
        return m_SpellEntry;
    }

    int DurationRemaining()
    {
        return m_AuraRec.EndTime == 0 ? 0 : m_AuraRec.EndTime - PerformanceCount();
    }

private:
    uint64 m_CreatorGUID;
    AuraRec m_AuraRec;
    SpellEntryRec m_SpellEntry;
};