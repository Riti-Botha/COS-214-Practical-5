FROM gcc:11 AS builder

WORKDIR /app
COPY . .
RUN make

FROM debian:bookworm-slim

WORKDIR /app
COPY --from=builder /app/campusguard /app/campusguard

CMD ["./campusguard"]