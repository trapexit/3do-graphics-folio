#include "graphics2_folio.h"
#include "version.h"

#include "folio.h"
#include "kernel.h"
#include "kernelnodes.h"
#include "nodes.h"
#include "stdio.h"
#include "types.h"

static Folio *g_Graphics2FolioBase;


Err
OpenGraphics2Folio(void)
{
  Item item;
  
  printf("OpenGraphics2Folio: version='%s'\n",VERSION);
  item = FindAndOpenFolio("graphics2");
  printf("OpenGraphics2Folio: FindAndOpenFolio(\"graphics2\") = %x\n",item);
  if(item < 0)
    return (Err)item;

  g_Graphics2FolioBase = (Folio*)LookupItem(item);

  return 0;
}

Err
CloseGraphics2Folio(void)
{
  Err err;

  err = CloseItem(g_Graphics2FolioBase->fn.n_Item);

  printf("CloseGraphics2Folio: CloseItem(item) = %x\n",err);

  return err;
}
