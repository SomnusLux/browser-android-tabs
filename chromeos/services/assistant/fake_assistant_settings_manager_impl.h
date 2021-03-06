// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROMEOS_SERVICES_ASSISTANT_FAKE_ASSISTANT_SETTINGS_MANAGER_IMPL_H_
#define CHROMEOS_SERVICES_ASSISTANT_FAKE_ASSISTANT_SETTINGS_MANAGER_IMPL_H_

#include <memory>
#include <string>

#include "chromeos/services/assistant/assistant_settings_manager.h"
#include "chromeos/services/assistant/public/mojom/settings.mojom.h"
#include "mojo/public/cpp/bindings/binding_set.h"

namespace chromeos {
namespace assistant {

class FakeAssistantSettingsManagerImpl : public AssistantSettingsManager {
 public:
  FakeAssistantSettingsManagerImpl();
  ~FakeAssistantSettingsManagerImpl() override;

  // mojom::AssistantSettingsManager overrides:
  void GetSettings(const std::string& selector,
                   GetSettingsCallback callback) override;
  void UpdateSettings(const std::string& update,
                      UpdateSettingsCallback callback) override;
  void StartSpeakerIdEnrollment(
      bool skip_cloud_enrollment,
      mojom::SpeakerIdEnrollmentClientPtr client) override;
  void StopSpeakerIdEnrollment(
      StopSpeakerIdEnrollmentCallback callback) override;
  void SyncSpeakerIdEnrollmentStatus() override {}

  // AssistantSettingsManager overrides:
  void BindRequest(mojom::AssistantSettingsManagerRequest request) override;

 private:
  mojo::BindingSet<mojom::AssistantSettingsManager> bindings_;

  DISALLOW_COPY_AND_ASSIGN(FakeAssistantSettingsManagerImpl);
};

}  // namespace assistant
}  // namespace chromeos

#endif  // CHROMEOS_SERVICES_ASSISTANT_FAKE_ASSISTANT_SETTINGS_MANAGER_IMPL_H_
