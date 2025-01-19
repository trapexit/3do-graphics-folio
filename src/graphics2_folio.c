/*
  ISC License

  Copyright (c) 2024, Antonio SJ Musumeci <trapexit@spawn.link>

  Permission to use, copy, modify, and/or distribute this software for any
  purpose with or without fee is hereby granted, provided that the above
  copyright notice and this permission notice appear in all copies.

  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#include "graphics2_folio.h"
#include "version.h"

#include "svc_funcs.h"

#include "hardware_addrs.h"
#include "kernel.h"
#include "kernelnodes.h"
#include "operror.h"
#include "stdio.h"
#include "types.h"

static i32  _Graphics2FolioInit(Graphics2Folio*);
static i32  _Graphics2FolioOpen(Graphics2Folio*);
static void _Graphics2FolioClose(Graphics2Folio*);
static i32  _Graphics2FolioDelete(Graphics2Folio*);

static void _user_func(void);
static void _swi_func(void);

static
FolioFunc
FolioUserFuncs[] =
  {
    /* add new functions at the top */
    //(FolioFunc),   /* -2, USER_ */
    (FolioFunc)_user_func    /* -1, USER_FUNC */
  };
#define NUM_USERFUNCS (sizeof(FolioUserFuncs)/sizeof(FolioFunc))

static
FolioFunc
FolioSWIFuncs[] =
  {
    /* add new functions at the top */
    //(FolioFunc)_SWI_, /* 3, SWI_ */
    //(FolioFunc)_SWI_, /* 2, SWI_ */
    //(FolioFunc)_SWI_, /* 1, SWI_ */
    (FolioFunc)_swi_func  /* 0, SWI_func */
  };
#define NUM_SWIFUNCS (sizeof(FolioSWIFuncs)/sizeof(FolioFunc))

/* Tags used when creating the Folio */
static TagArg g_FolioTags[] =
  {
    { TAG_ITEM_NAME,            (void*)"graphics2" }, /* name of folio */
    { TAG_ITEM_PRI,             (void*)0 },
    { CREATEFOLIO_TAG_ITEM,     (void*)GRAPHICS2_FOLIO },
    { CREATEFOLIO_TAG_DATASIZE, (void*)sizeof(Graphics2Folio) },
    { CREATEFOLIO_TAG_NUSERVECS,(void*)NUM_USERFUNCS }, /* number of user functions */
    { CREATEFOLIO_TAG_USERFUNCS,(void*)FolioUserFuncs }, /* list of user functions */
    { CREATEFOLIO_TAG_NSWIS,    (void*)NUM_SWIFUNCS }, /* number of swi functions */
    { CREATEFOLIO_TAG_SWIS,     (void*)FolioSWIFuncs }, /* list of swi functions */
    { CREATEFOLIO_TAG_INIT,     (void*)_Graphics2FolioInit },
    { CREATEFOLIO_TAG_OPENF,    (void*)_Graphics2FolioOpen },
    { CREATEFOLIO_TAG_CLOSEF,   (void*)_Graphics2FolioClose },
    { CREATEFOLIO_TAG_DELETEF,  (void*)_Graphics2FolioDelete },
    { TAG_END,                  (void*)0 }, /* end of tag list */
  };

int
main(i32    argc_,
     char **argv_)
{
  Item rv;

  (void)argv_;
  if(argc_ != DEMANDLOAD_MAIN_CREATE)
    return 0;

  printf("Graphics2Folio: version='%s'\n",VERSION);
  rv = CreateItem(MKNODEID(KERNELNODE,FOLIONODE),g_FolioTags);
  if(rv >= 0)
    {
      printf("Graphics2Folio: item=%x\n",rv);
    }
  else
    {
      printf("Graphics2Folio: creation failed - ");
      PrintfSysErr(rv);
    }

  return (int)rv;
}

static
i32
_Graphics2FolioInit(Graphics2Folio *ef_)
{
  svc_kprintf("Graphics2FolioInit: ef=%p\n",ef_);

  return 0;
}

static
i32
_Graphics2FolioOpen(Graphics2Folio *ef_)
{
  svc_kprintf("Graphics2FolioOpen: ef=%p\n",ef_);

  return 0;
}

static
void
_Graphics2FolioClose(Graphics2Folio *ef_)
{
  svc_kprintf("Graphics2FolioClose: ef=%p\n",ef_);
}

static
i32
_Graphics2FolioDelete(Graphics2Folio *ef_)
{
  svc_kprintf("Graphics2FolioDelete: ef=%p\n",ef_);

  return 0;
}


static
void
_user_func(void)
{

}

static
void
_swi_func(void)
{

}
