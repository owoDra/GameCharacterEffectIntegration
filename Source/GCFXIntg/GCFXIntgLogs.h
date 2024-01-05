// Copyright (C) 2023 owoDra

#pragma once

#include "Logging/LogMacros.h"

GCFXINTG_API DECLARE_LOG_CATEGORY_EXTERN(LogGCFXI, Log, All);

#if !UE_BUILD_SHIPPING

#define GCFXILOG(FormattedText, ...) UE_LOG(LogGCFXI, Log, FormattedText, __VA_ARGS__)

#define GCFXIENSURE(InExpression) ensure(InExpression)
#define GCFXIENSURE_MSG(InExpression, InFormat, ...) ensureMsgf(InExpression, InFormat, __VA_ARGS__)
#define GCFXIENSURE_ALWAYS_MSG(InExpression, InFormat, ...) ensureAlwaysMsgf(InExpression, InFormat, __VA_ARGS__)

#define GCFXICHECK(InExpression) check(InExpression)
#define GCFXICHECK_MSG(InExpression, InFormat, ...) checkf(InExpression, InFormat, __VA_ARGS__)

#else

#define GCFXILOG(FormattedText, ...)

#define GCFXIENSURE(InExpression) InExpression
#define GCFXIENSURE_MSG(InExpression, InFormat, ...) InExpression
#define GCFXIENSURE_ALWAYS_MSG(InExpression, InFormat, ...) InExpression

#define GCFXICHECK(InExpression) InExpression
#define GCFXICHECK_MSG(InExpression, InFormat, ...) InExpression

#endif