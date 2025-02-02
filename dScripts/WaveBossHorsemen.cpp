#include "WaveBossHorsemen.h"
#include "BaseCombatAIComponent.h"

void WaveBossHorsemen::OnStartup(Entity *self) {
    BaseWavesGenericEnemy::OnStartup(self);

    auto* combatAIComponent = self->GetComponent<BaseCombatAIComponent>();
    if (combatAIComponent != nullptr) {
        combatAIComponent->SetDisabled(true);
        combatAIComponent->SetStunImmune(true);
    }

    self->AddToGroup("boss");
}

void
WaveBossHorsemen::OnFireEventServerSide(Entity *self, Entity *sender, std::string args, int32_t param1, int32_t param2,
                                        int32_t param3) {
    if (args == "startAI") {
        auto* combatAIComponent = self->GetComponent<BaseCombatAIComponent>();
        if (combatAIComponent != nullptr) {
            combatAIComponent->SetDisabled(false);
        }
    }
}
