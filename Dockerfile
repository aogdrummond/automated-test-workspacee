# Use Debian 11 as base image
FROM debian:11

# Set the working directory inside the container
WORKDIR /app

# Copy the source code and dependencies into the container
COPY . /app/

# Install necessary build tools and dependencies for C++ compilation
RUN apt-get update && \
    apt-get install -y build-essential && \
    apt-get clean

# Compile the C++ code and link the test executable
RUN g++ -std=c++14 -Igoogletest/googletest/include -Igoogletest/googletest -c googletest/googletest/src/gtest-all.cc -o gtest-all.o && \
    g++ -std=c++14 -Igoogletest/googletest/include -Igoogletest/googletest -c myfunction.cpp -o myfunction.o && \
    g++ -std=c++14 -Igoogletest/googletest/include -Igoogletest/googletest -c mytests.cpp -o mytests.o && \
    g++ -o mytests.exe myfunction.o mytests.o gtest-all.o -Lgoogletest/googletest -lpthread

# Run the compiled C++ executable
CMD ["./mytests.exe"]

