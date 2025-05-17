/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Central place to rename/modify keys, using C++
 * @version 0.1
 * @date 2025-05-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <vector>
#include <unordered_map>

// ---------- Interface ----------
class ISensorAdapter
{
public:
    virtual ~ISensorAdapter() = default;
    virtual std::map<std::string, std::string> getData() const = 0;
};

// ---------- Key Mapper ----------
class KeyMapper
{
public:
    void addMapping(const std::string &original, const std::string &mapped)
    {
        keyMap[original] = mapped;
    }

    std::string mapKey(const std::string &original) const
    {
        auto it = keyMap.find(original);
        return it != keyMap.end() ? it->second : original;
    }

    std::map<std::string, std::string> remapKeys(const std::map<std::string, std::string> &input) const
    {
        std::map<std::string, std::string> result;

        for (const auto &pair : input)
        {
            result[mapKey(pair.first)] = pair.second;
        }

        return result;
    }

private:
    std::unordered_map<std::string, std::string> keyMap;
};

// ---------- Adapters ----------
class SensorSettingAdapter : public ISensorAdapter
{
public:
    std::map<std::string, std::string> getData() const override
    {
        return {
            {"samplingRate", "100"},
            {"unit", "Celsius"}};
    }
};

class SensorCalibrationAdapter : public ISensorAdapter
{
public:
    std::map<std::string, std::string> getData() const override
    {
        return {
            {"offset", "1.5"},
            {"scale", "0.98"}};
    }
};

class SensorHistoryAdapter : public ISensorAdapter
{
public:
    std::map<std::string, std::string> getData() const override
    {
        return {
            {"lastCalibrated", "2025-05-17"},
            {"calibratedBy", "Technician A"}};
    }
};

// ---------- Aggregator ----------
class SensorDataAggregator
{
public:
    SensorDataAggregator()
    {
        // shiv
        auto keyMapper = std::make_shared<KeyMapper>();

        keyMapper->addMapping("samplingRate", "Sampling Rate");
        keyMapper->addMapping("unit", "Unit");
        keyMapper->addMapping("offset", "Calibration Offset");
        keyMapper->addMapping("scale", "Calibration Scale");
        keyMapper->addMapping("lastCalibrated", "Last Calibrated");
        keyMapper->addMapping("calibratedBy", "Calibrated By");

        setKeyMapper(keyMapper);
    }

    void setAdapters(const std::vector<std::shared_ptr<ISensorAdapter>> &adapters)
    {
        m_adapters = adapters;
    }

    void setKeyMapper(std::shared_ptr<KeyMapper> mapper)
    {
        m_keyMapper = std::move(mapper);
    }

    std::map<std::string, std::string> aggregateData() const
    {
        std::map<std::string, std::string> result;

        for (const auto &adapter : m_adapters)
        {
            auto data = adapter->getData();

            auto mappedData = m_keyMapper ? m_keyMapper->remapKeys(data) : data;

            result.insert(mappedData.begin(), mappedData.end());
        }

        return result;
    }

private:
    std::vector<std::shared_ptr<ISensorAdapter>> m_adapters;
    std::shared_ptr<KeyMapper> m_keyMapper;
};

// ---------- Main ----------
int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    auto settingAdapter = std::make_shared<SensorSettingAdapter>();
    auto calibrationAdapter = std::make_shared<SensorCalibrationAdapter>();
    auto historyAdapter = std::make_shared<SensorHistoryAdapter>();

    // auto keyMapper = std::make_shared<KeyMapper>();
    // keyMapper->addMapping("samplingRate", "Sampling Rate");
    // keyMapper->addMapping("unit", "Unit");
    // keyMapper->addMapping("offset", "Calibration Offset");
    // keyMapper->addMapping("scale", "Calibration Scale");
    // keyMapper->addMapping("lastCalibrated", "Last Calibrated");
    // keyMapper->addMapping("calibratedBy", "Calibrated By");

    SensorDataAggregator aggregator;

     aggregator.setAdapters({settingAdapter, calibrationAdapter, historyAdapter});
    //aggregator.setAdapters({settingAdapter});

    // aggregator.setKeyMapper(keyMapper);

    auto data = aggregator.aggregateData();

    for (const auto &pair : data)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
