## What
  gtest sample code

## install
    unzip gtest-1.6.0.zip
    g++ -I ${GTEST_DIR}/include -I ${GTEST_DIR} -c ${GTEST_DIR}/src/gtest-all.cc
    ar -rv libgtest.a gtest-all.o
    cp libgtest.a ${PROJECT}/test # 配置先に迷った

## run test

    make all

## if use guard

### install

    gem install guard-shell

### useage

    guard

file save -> auto test

### see

- https://github.com/guard/guard/
- https://github.com/guard/guard-shell