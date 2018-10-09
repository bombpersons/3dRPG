#! /usr/bin/env python
# encoding: utf-8

import os

APPNAME = '3dRPG'
VERSION = '0.1'

top = '.'
out = 'build'

# Pretty horrible, but convenient.
def __recurse(ctx):
    for dir in os.listdir(ctx.path.abspath()):
        if (os.path.isdir(dir)):
            if os.path.isfile(os.path.join(dir, 'wscript')):
                ctx.recurse(dir)

def options(ctx):
    ctx.load('compiler_cxx')
    ctx.add_option('--debug', action='store', default=False, help='Build with debug symbols')
    __recurse(ctx)

def configure(ctx):
    ctx.load('compiler_cxx')
    __recurse(ctx)

def build(ctx):
    if ctx.options.debug == 'True':
        ctx.env.append_value('CXXFLAGS', ['-g3', '-Wall'])
    else:
        ctx.env.append_value('CXXFLAGS', ['-O3'])

    __recurse(ctx)
