cdc_class = stm32cube.get_variable('usbd_cdc_dep')

thermo = executable(
    'thermo',
    ['thermo.c', 'stm32f4xx_it.c', 'usbd_conf.c', 'usbd_desc.c', 'usbd_cdc_if.c', 'pcd.c'],
    name_suffix: 'elf',
    dependencies: [stm32_system, stm32_startup, stm32_ll, stm32_hal, usbd_core, cdc_class],
    link_args: ['-T', linker]
)
thermo_bin = custom_target(
  'thermo_bin',
  input: thermo,
  output: 'thermo.bin',
  command: convert_bin_cmd,
  build_by_default: true
)
