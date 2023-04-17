# smp_srv Direct-XIP

## zephyr upstream

### MCUboot

```sh
west build --pristine -b nrf52840dk_nrf52840 -d build_mcuboot ../../../../../../bootloader/mcuboot/boot/zephyr -- -DOVERLAY_CONFIG=${PWD}/configs/overlay-mcuboot.conf
```

### App - slot0

```sh
west build --pristine -b nrf52840dk_nrf52840 -d build_slot0 -- -DOVERLAY_CONFIG='overlay-bt.conf;configs/overlay-app.conf'
```

### App - slot1

```sh
west build --pristine -b nrf52840dk_nrf52840 -d build_slot1 -- -DOVERLAY_CONFIG='overlay-bt.conf;configs/overlay-app.conf' -DDTC_OVERLAY_FILE=configs/nrf52840dk_nrf52840_slot1.overlay
```

### Signing

```sh
west sign -t imgtool -d build_slot0 -- --key bootloader/mcuboot/root-rsa-2048.pem --version 0.0.0+0
west sign -t imgtool -d build_slot1 -- --key bootloader/mcuboot/root-rsa-2048.pem --version 1.0.0+0
```

## ncs

```sh
west build --pristine -b nrf52840dk_nrf52840 -d build_both -- -DOVERLAY_CONFIG='overlay-bt.conf;configs/overlay-app.conf' -Dmcuboot_OVERLAY_CONFIG='../../../../zephyr/samples/subsys/mgmt/mcumgr/smp_svr/configs/overlay-mcuboot.conf' -DCONFIG_MCUBOOT_IMAGE_VERSION=\"0.0.0+0\"
```
