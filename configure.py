from tea.build_tools import Ninja, cpp_executable

ninja = Ninja()

with ninja:
    cpp_executable(
        'examples/basic/main',
        srcs=[
            'examples/basic/main.cpp'
        ],
        include_dirs=['.']
    )

ninja.save()
