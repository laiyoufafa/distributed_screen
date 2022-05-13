/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "dscreen_sink_load_callback.h"

#include <unistd.h>

#include "hisysevent.h"

#include "dscreen_errcode.h"
#include "dscreen_log.h"
#include "dscreen_sink_handler.h"

namespace OHOS {
namespace DistributedHardware {
DScreenSinkLoadCallback::DScreenSinkLoadCallback(
    const std::string &params) : params_(params) {}

void DScreenSinkLoadCallback::OnLoadSystemAbilitySuccess(
    int32_t systemAbilityId, const sptr<IRemoteObject> &remoteObject)
{
    DHLOGI("load screen SA success, systemAbilityId:%d, remoteObject result:%s",
        systemAbilityId, (remoteObject != nullptr) ? "true" : "false");
    if (remoteObject == nullptr) {
        DHLOGE("remoteObject is nullptr");
        return;
    }

    DScreenSinkHandler::GetInstance().FinishStartSA(params_, remoteObject);
}

void DScreenSinkLoadCallback::OnLoadSystemAbilityFail(int32_t systemAbilityId)
{
    DHLOGE("load screen SA failed, systemAbilityId:%d", systemAbilityId);
    int32_t res = OHOS::HiviewDFX::HiSysEvent::Write(
        OHOS::HiviewDFX::HiSysEvent::Domain::DISTRIBUTED_SCREEN,
        "SA_ERROR",
        OHOS::HiviewDFX::HiSysEvent::EventType::FAULT,
        "PID", getpid(),
        "UID", getuid(),
        "MSG", "dscreen sink OnLoadSystemAbilityFail.");
    if (res != DH_SUCCESS) {
        DHLOGE("Write HiSysEvent error, res:%d", res);
    }
}
}
}