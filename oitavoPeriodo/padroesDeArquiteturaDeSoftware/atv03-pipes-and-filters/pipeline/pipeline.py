from pipeline.filter import Filter


class Pipeline(Filter):
    def __init__(self, filters):
        if len(filters) == 0:
            raise ValueError("Um pipeline precisa de pelo menos um filtro.")
        self.filters = filters

    def process(self, data):
        result = data
        for current_filter in self.filters:
            result = current_filter.process(result)
        return result

    def steps(self):
        names = []
        for current_filter in self.filters:
            names.append(type(current_filter).__name__)
        return names
