#!/bin/bash

VALUE=$1

cat > include/config.h << EOF
#ifndef CONFIG_H
#define CONFIG_H

#define OS_ENV $VALUE

#endif
EOF

echo "config.h configuré."