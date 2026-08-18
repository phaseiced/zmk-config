# Keyball44 PMW3360 module (vendored)

Based on KOHSUK / bullwinkle3000 `pmw3360` driver:

- Uploads PixArt SROM firmware (required for proper tracking)
- `irq-gpios` optional — omit to poll (stock Keyball 7-pin J2 has no MOTION)
- `CONFIG_PMW3360_FORCE_AWAKE` keeps Config2=0x00 like QMK Keyball

Loaded via repo-root `zephyr/module.yml` (ZMK user-config `ZMK_EXTRA_MODULES`).
