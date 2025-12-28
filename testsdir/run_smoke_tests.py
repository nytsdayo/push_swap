#!/usr/bin/env python3
"""
Basic execution checks for push_swap.

The script builds the project, runs a few sample inputs, and replays the
operations to confirm the stacks end up sorted (or that an error is reported
when expected).
"""

from __future__ import annotations

import subprocess
import sys
from pathlib import Path
from typing import List, Tuple

ROOT = Path(__file__).resolve().parent.parent
BINARY = ROOT / "push_swap"

TEST_CASES: Tuple[Tuple[str, List[str], bool], ...] = (
    ("already_sorted", ["1", "2", "3"], False),
    ("reverse_three", ["3", "2", "1"], False),
    ("five_numbers", ["8", "3", "5", "1", "4"], False),
    ("duplicate_error", ["4", "4"], True),
)


def build_binary() -> None:
    subprocess.run(["make"], cwd=ROOT, check=True)


def apply_operation(
    stack_a: List[int], stack_b: List[int], op: str
) -> Tuple[List[int], List[int]]:
    if op in ("sa", "sb"):
        if len(stack_a) < 2:
            return stack_a, stack_b
        if op == "sa":
            stack_a[0], stack_a[1] = stack_a[1], stack_a[0]
        else:
            stack_b[0], stack_b[1] = stack_b[1], stack_b[0]
    elif op == "pa":
        if stack_b:
            stack_a.insert(0, stack_b.pop(0))
    elif op == "pb":
        if stack_a:
            stack_b.insert(0, stack_a.pop(0))
    elif op == "ra":
        if len(stack_a) >= 2:
            stack_a.append(stack_a.pop(0))
    elif op == "rb":
        if len(stack_b) >= 2:
            stack_b.append(stack_b.pop(0))
    elif op == "rra":
        if len(stack_a) >= 2:
            stack_a.insert(0, stack_a.pop())
    elif op == "rrb":
        if len(stack_b) >= 2:
            stack_b.insert(0, stack_b.pop())
    else:
        raise ValueError(f"Unsupported operation: {op}")
    return stack_a, stack_b


def replay_operations(
    args: List[str], operations: List[str]
) -> Tuple[List[int], List[int]]:
    stack_a = [int(value) for value in args]
    stack_b: List[int] = []
    for op in operations:
        stack_a, stack_b = apply_operation(stack_a, stack_b, op)
    return stack_a, stack_b


def is_sorted(values: List[int]) -> bool:
    return all(values[i] <= values[i + 1] for i in range(len(values) - 1))


def run_case(
    name: str, args: List[str], expect_error: bool
) -> Tuple[bool, str]:
    result = subprocess.run(
        [str(BINARY), *args],
        capture_output=True,
        text=True,
    )
    if expect_error:
        if result.returncode == 0:
            return False, f"{name}: expected error but exited with 0"
        return True, f"{name}: expected error received"
    operations = [
        line.strip()
        for line in result.stdout.splitlines()
        if line.strip()
    ]
    stack_a, stack_b = replay_operations(args, operations)
    if result.returncode != 0:
        return False, f"{name}: non-zero exit ({result.returncode})"
    if stack_b:
        return False, f"{name}: stack_b not empty after operations"
    if not is_sorted(stack_a):
        return False, f"{name}: stack_a not sorted after operations"
    return True, f"{name}: ok ({len(operations)} operations)"


def main() -> int:
    build_binary()
    failures = []
    for name, args, expect_error in TEST_CASES:
        success, message = run_case(name, args, expect_error)
        print(("[OK] " if success else "[NG] ") + message)
        if not success:
            failures.append(message)
    if failures:
        print("\nFailures detected:")
        for message in failures:
            print(f"- {message}")
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
