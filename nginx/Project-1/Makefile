.PHONY: help setup build run test clean docker-up docker-down docker-logs

help:
	@echo "REST API Server - Available Commands"
	@echo "===================================="
	@echo "make setup      - Install all dependencies"
	@echo "make build      - Build the project"
	@echo "make run        - Run the REST API server"
	@echo "make test       - Test the API endpoints"
	@echo "make clean      - Clean build artifacts"
	@echo "make docker-up  - Start Nginx & Redis with Docker Compose"
	@echo "make docker-down - Stop Docker Compose services"
	@echo "make docker-logs - View Docker Compose logs"

setup:
	@./setup.sh

build:
	@./build.sh

run: build
	@echo "Starting REST API Server on port 8080..."
	@cd build && ./bin/rest_server

test:
	@./test.sh

clean:
	@echo "Cleaning build artifacts..."
	@rm -rf build/bin build/CMakeFiles build/cmake_install.cmake build/Makefile build/CMakeCache.txt
	@echo "Clean complete"

docker-up:
	@echo "Starting Docker services..."
	@docker-compose up -d
	@echo "Services started. Check with: docker-compose ps"

docker-down:
	@echo "Stopping Docker services..."
	@docker-compose down

docker-logs:
	@docker-compose logs -f

all: setup build run
