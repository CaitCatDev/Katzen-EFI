#include <kuefi/lib/kuefi.h>
#include <kuefi/efi.h>
#include <stdarg.h>

void kuefi_put8(char8 ch) {
	char16 str[2];
	str[0] = ch;
	str[1] = 0;
	
	GST->conout->output_string(GST->conout, str);
}

void keufi_put(char16 ch) {
	char16 str[2];
	str[0] = ch;
	str[1] = 0;
	
	GST->conout->output_string(GST->conout, str);
}

void kuefi_puts(char16 *Str) {
	GST->conout->output_string(GST->conout, Str);
}

void kuefi_print_hex(uint64_t Hex) {
	char16 ptr_str[32];
	int i = 15;
	static char16 *HexChars = (char16 *)L"0123456789ABCDEF";
	ptr_str[16] = 0;

	while(Hex) {
		ptr_str[i] = HexChars[(Hex % 16)];
		i--;
		Hex /= 16;

		if(i == 0) break;
	}
	GST->conout->output_string(GST->conout, &ptr_str[i+1]);
}

void kuefi_print_hex_length(uint64_t Hex, uint64_t ToPrint) {
	char16 ptr_str[32];
	int i = 15;
	static char16 *HexChars = (char16 *)L"0123456789ABCDEF";
	ptr_str[16] = 0;

	while(ToPrint) {
		ptr_str[i] = HexChars[(Hex % 16)];
		i--;
		ToPrint--;
		Hex /= 16;

		if(i == 0) break;
	}
	GST->conout->output_string(GST->conout, &ptr_str[i+1]);
}

static void kuefi_print_guid(efi_guid_t guid) {
	int i = 0;

	kuefi_print_hex_length(guid.data1, 8);
	GST->conout->output_string(GST->conout, (char16*)L"-");
	kuefi_print_hex_length(guid.data2, 4);
	GST->conout->output_string(GST->conout, (char16*)L"-");	
	kuefi_print_hex_length(guid.data3, 4);
	for(i =	0; i < 8; ++i) {
		GST->conout->output_string(GST->conout, (char16*)L"-");	
		kuefi_print_hex_length(guid.data4[i], 2);
	}
}

/* A very basic formatted print function
 * Not great but not terrible either
 */
int32_t kuefi_printf(char16 *fmt, ...) {
	va_list args;
	uintn_t iter;
	int32_t LengthOutputted;

	va_start(args, fmt);
	
	for(iter = 0; fmt[iter] != '\0'; iter++) {
		if(fmt[iter] != '%') {
			keufi_put(fmt[iter]);
			continue;
		}
		/*Char was %*/
		switch (fmt[iter + 1]) {
			case L'a':
			case L'c':
				keufi_put(va_arg(args, int32_t));
				break;
			case L'p':
			case L'X':
				kuefi_puts((char16*)L"0x");
			case L'x':
				kuefi_print_hex(va_arg(args, uint64_t));
				break;
			case L'%':
				keufi_put(L'%');
				break;
			case L's':
				kuefi_puts(va_arg(args, char16 *));
				break;
			case L'i':
			case L'd':
				va_arg(args, int32_t);
				break;
			case L'G':
				kuefi_print_guid(va_arg(args, efi_guid_t));
				break;
			case L'.': {
				uintn_t Length = va_arg(args, uintn_t);

				switch (fmt[iter + 2]) {
					case 'p':
					case 'X':
						kuefi_puts((char16*)L"0x");
					case 'x':
						kuefi_print_hex_length(va_arg(args, uintn_t), Length);
						break;
					default:
						kuefi_puts((char16*)L"?");
				}

				iter++;
				break;
			}
			default:
				keufi_put(L'?');
		}

		iter++;
	}

	va_end(args);

	return 0;
}
