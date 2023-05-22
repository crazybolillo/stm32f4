project(
  'stm32f4',
  ['c', 'cpp'],
  version: '0.1',
  default_options: [
    'default_library=static',
    'warning_level=0',
    'werror=true',
    'c_std=c17',
    'cpp_std=c++20'
    ]
)

program = get_option('program').strip()
if program == ''
  error('Please specify which program to build')
endif

linker = meson.current_source_dir() + '/' + target_machine.cpu() + '.ld'

stm32cube = subproject('STM32CubeF4')
stm32_inc = stm32cube.get_variable('inc')
stm32_system = stm32cube.get_variable('system_f4xx')
stm32_startup = stm32cube.get_variable('startup_f401xc')
ll_rcc = stm32cube.get_variable('ll_rcc')
ll_gpio = stm32cube.get_variable('ll_gpio')
ll_utils = stm32cube.get_variable('ll_utils')

objcopy = find_program('arm-none-eabi-objcopy')
convert_bin_cmd = [objcopy, '-O', 'binary', '@INPUT@',  '@OUTPUT@']

subdir(program)
