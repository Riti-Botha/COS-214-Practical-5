# COS-214-Practical-5
## Running with Docker

Build and run the complete application:

```bash
docker compose up --build
```

This builds the CampusGuard image (compiling with the project's Makefile inside the
container, `g++ -std=c++11`) and starts the application. Docker will display the
build steps followed by the program's runtime output.

To stop the running container:

```bash
docker compose down
```

To rebuild from scratch after code changes:

```bash
docker compose build --no-cache
docker compose up
```