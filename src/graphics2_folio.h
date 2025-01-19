#pragma once
#pragma force_top_level

#include "types.h"
#include "folio.h"

#define GRAPHICS2_FOLIO 'G'
#define GRAPHICS2_FOLIO_SWI (GRAPHICS2_FOLIO << 16)

typedef struct Graphics2Folio Graphics2Folio;

struct Graphics2Folio
{
  Folio folio;
};

#ifdef __cplusplus
extern "C" {
#endif

Err OpenGraphics2Folio(void);
Err CloseGraphics2Folio(void);

#ifdef __cplusplus
}
#endif
