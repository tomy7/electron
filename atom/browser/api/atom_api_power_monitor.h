// Copyright (c) 2013 GitHub, Inc. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ATOM_BROWSER_API_ATOM_API_POWER_MONITOR_H_
#define ATOM_BROWSER_API_ATOM_API_POWER_MONITOR_H_

#include "atom/browser/api/event_emitter.h"
#include "base/compiler_specific.h"
#include "base/power_monitor/power_observer.h"
#include "native_mate/handle.h"

namespace atom {

namespace api {

class PowerMonitor : public mate::EventEmitter,
                     public base::PowerObserver {
 public:
  static mate::Handle<PowerMonitor> Create(v8::Isolate* isolate);

 protected:
  explicit PowerMonitor();
  virtual ~PowerMonitor();

  // base::PowerObserver implementations:
  virtual void OnPowerStateChange(bool on_battery_power) OVERRIDE;
  virtual void OnSuspend() OVERRIDE;
  virtual void OnResume() OVERRIDE;

  DISALLOW_COPY_AND_ASSIGN(PowerMonitor);
};

}  // namespace api

}  // namespace atom

#endif  // ATOM_BROWSER_API_ATOM_API_POWER_MONITOR_H_
