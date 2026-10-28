
#include <stdio.h>
#include <stdlib.h>
#include <libusb-1.0/libusb.h>

int main(void)
{
    libusb_context *context = NULL;
    libusb_device **devices = NULL;

    printf("================================\n");
    printf("      Switch USB Inspector\n");
    printf("             v0.1\n");
    printf("================================\n\n");

    if (libusb_init(&context) != 0) {
        fprintf(stderr, "Erro ao inicializar o libusb.\n");
        return EXIT_FAILURE;
    }

    ssize_t count = libusb_get_device_list(context, &devices);

    if (count < 0) {
        fprintf(stderr, "Erro ao listar dispositivos USB.\n");
        libusb_exit(context);
        return EXIT_FAILURE;
    }

    printf("Dispositivos USB encontrados: %zd\n\n", count);

    for (ssize_t i = 0; i < count; i++) {
        struct libusb_device_descriptor desc;

        if (libusb_get_device_descriptor(devices[i], &desc) != 0) {
            continue;
        }

        printf("Dispositivo #%zd\n", i + 1);
        printf("  VID:PID: %04X:%04X\n",
               desc.idVendor, desc.idProduct);
        printf("  Versao USB: %u.%02u\n",
               desc.bcdUSB >> 8, desc.bcdUSB & 0xFF);
        printf("  Classe USB: 0x%02X\n",
               desc.bDeviceClass);
        printf("  Configuracoes: %u\n\n",
               desc.bNumConfigurations);
    }

    libusb_free_device_list(devices, 1);
    libusb_exit(context);

    return EXIT_SUCCESS;
}
