import logging

# Specify what level of logging starts printing out to the terminal
# logging.basicConfig(level=logging.DEBUG)

# Log to an external File
# logging.basicConfig(
#     filename="my_logs.log", encoding="utf-8", filemode="w", level=logging.DEBUG
# )

logging.basicConfig(
    format="%(levelname)s (%(asctime)s): %(message)s (Line: %(lineno)d [%(filename)s])",
    datefmt="%m/%d/%Y %I:%M:%S %p",
    level=logging.DEBUG,
)

# Logging Levels
# logging.debug("DEBUG")
# logging.info("INFO")
# logging.warning("WARNING")
# logging.error("ERROR")
# logging.critical("CRITICAL")

x: int = 10 + 10

logging.info(f"The answer is: {x}")
