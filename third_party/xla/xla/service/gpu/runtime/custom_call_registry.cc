/* Copyright 2023 The OpenXLA Authors.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "xla/service/gpu/runtime/custom_call_registry.h"

#include <functional>
#include <vector>

#include "xla/runtime/custom_call_registry.h"

namespace xla::gpu {

using DirectCustomCallRegistration =
    std::function<void(runtime::DirectCustomCallRegistry&)>;

static std::vector<DirectCustomCallRegistration>*
DirectCustomCallRegistrations() {
  static auto* storage = new std::vector<DirectCustomCallRegistration>();
  return storage;
}

void AddDirectCustomCallRegistration(
    DirectCustomCallRegistration registration) {
  DirectCustomCallRegistrations()->push_back(registration);
}

// Registers all direct custom calls with the given registry.
void RegisterDirectCustomCalls(runtime::DirectCustomCallRegistry& registry) {
  for (auto& registration : *DirectCustomCallRegistrations()) {
    registration(registry);
  }
}

}  // namespace xla::gpu
