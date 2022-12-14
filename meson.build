project('nnew', 'cpp')
raylib = dependency('raylib')

inc_dir = include_directories('include')

sources = files( 'main.cpp',
            'src/animation.cpp',
            'src/ball.cpp',
            'src/ball_collection.cpp',
            'src/drawable.cpp',
            'src/drawable_collection.cpp',
            'src/math_overloads.cpp',
            'src/text_ball.cpp',
            'src/timer.cpp',
            'src/util.cpp',
            )

new = executable(
    'out',
    [sources], include_directories: [inc_dir], dependencies: [raylib]
    )
