#pragma once
#include <Uefi.h>
#include <Guid/FileInfo.h>
#include <Guid/FileSystemInfo.h>
#include <Library/DebugLib.h>
#include <Library/DevicePathLib.h>
#include <Library/UefiApplicationEntryPoint.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Protocol/BlockIo.h>
#include <Library/PrintLib.h>
#include <Protocol/DevicePath.h>
#include <Protocol/LoadedImage.h>
#include <Protocol/SimpleFileSystem.h>
#include <Protocol/FormBrowser2.h>
#include <Protocol/FormBrowserEx.h>
#include <Protocol/FormBrowserEx2.h>
#include <Protocol/AcpiSystemDescriptionTable.h>
#include <Protocol/DisplayProtocol.h>
#include <Protocol/HiiPopup.h>
#include <Library/MemoryAllocationLib.h>
#include <PiDxe.h>
#include <Protocol/FirmwareVolume2.h>
#include <Library/BaseMemoryLib.h>
#include <Protocol/RegularExpressionProtocol.h>

//Needed for ConvertStrToGuid
#define Align4(Value) (((Value)+3) & ~3)
#define Align8(Value) (((Value)+7) & ~7)
#define IS_COMMA(a)                ((a) == L',')
#define IS_HYPHEN(a)               ((a) == L'-')
#define IS_DOT(a)                  ((a) == L'.')
#define IS_LEFT_PARENTH(a)         ((a) == L'(')
#define IS_RIGHT_PARENTH(a)        ((a) == L')')
#define IS_SLASH(a)                ((a) == L'/')
#define IS_NULL(a)                 ((a) == L'\0')

//Set default lang Rus
BOOLEAN ENG = FALSE;

//Initizalize log function
VOID LogToFile(
  EFI_FILE *LogFile,
  CHAR16 *String
);

CHAR16 *FindLoadedImageFileName(
  IN EFI_LOADED_IMAGE_PROTOCOL *LoadedImage
);

UINTN FindLoadedImageBufferSize(
  IN EFI_LOADED_IMAGE_PROTOCOL *LoadedImage
);

EFI_STATUS LoadandRunImage(
  EFI_HANDLE ImageHandle,
  EFI_SYSTEM_TABLE *SystemTable,
  CHAR16 *FileName,
  EFI_HANDLE *AppImageHandle
);

UINT8 *FindBaseAddressFromName(
  const CHAR16 *Name
);

EFI_STATUS LocateAndLoadFvFromName(
  CHAR16 *Name,
  EFI_SECTION_TYPE Section_Type,
  UINT8 **Buffer,
  UINTN *BufferSize
);

EFI_STATUS LocateAndLoadFvFromGuid(
  EFI_GUID GUID16,
  EFI_SECTION_TYPE Section_Type,
  UINT8 **Buffer,
  UINTN *BufferSize
);

EFI_STATUS
RegexMatch(
  IN      UINT8 *DUMP,
  IN      CHAR16 *Pattern16,
  IN      UINT16 Size,
  OUT     BOOLEAN *Result
);

/*
EFI_STATUS ConvertStrToGuid(
  IN      CHAR16 *Str,
  OUT     EFI_GUID *Guid
);

EFI_STATUS ConvertStrToBuf(
  OUT     UINT8 *Buf,
  IN      UINTN  BufferLength,
  IN      CHAR16 *Str
);
*/
