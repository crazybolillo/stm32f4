thermo = executable(
    'thermo',
    'thermo.c',
    name_suffix: 'elf',
    include_directories: stm32_inc,
    dependencies: [stm32_system, stm32_startup, ll_rcc, ll_gpio, ll_utils],
    link_args: ['-T', linker]
)
main_bin = custom_target(
  'thermo_bin',
  input: thermo,
  output: 'thermo.bin',
  command: convert_bin_cmd,
  build_by_default: true
)
