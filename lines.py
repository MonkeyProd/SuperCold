import fnmatch
import os

matches = []

def find_files(extension:str):
	for root, dirnames, filenames in os.walk('src'):
		for filename in fnmatch.filter(filenames, '*.'+extension):
			matches.append(os.path.join(root, filename))

extensions=['cpp','hpp','h','c','toml']

for extension in extensions:
	find_files(extension)

matches = list(filter(lambda x: 'external' not in x, matches))
# print(matches)

total = 0

for match in matches:
	with open(match, 'r') as f:
		l = sum(1 for line in f if (len(line)>2 and not line.strip().startswith("/")))
		total += l
		print(l, match)

print(f'\n{total=}')
