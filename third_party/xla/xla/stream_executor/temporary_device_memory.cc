/* Copyright 2015 The OpenXLA Authors.

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

#include "xla/stream_executor/temporary_device_memory.h"

#include "xla/stream_executor/stream.h"

namespace stream_executor {

TemporaryDeviceMemoryBase::~TemporaryDeviceMemoryBase() {
  parent_->parent()->Deallocate(&device_memory_);
}

DeviceMemoryBase* TemporaryDeviceMemoryBase::mutable_device_memory() {
  return &device_memory_;
}

const DeviceMemoryBase& TemporaryDeviceMemoryBase::device_memory() const {
  return device_memory_;
}

TemporaryDeviceMemoryBase::TemporaryDeviceMemoryBase(
    Stream* parent, DeviceMemoryBase device_memory)
    : device_memory_(device_memory), parent_(parent) {}

}  // namespace stream_executor
