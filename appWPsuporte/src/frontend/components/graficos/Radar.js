import React, {Component} from 'react';
import {
    PolarGrid, RadarChart, PolarAngleAxis, PolarRadiusAxis, Radar, Legend, Tooltip, ResponsiveContainer
} from 'recharts';

const data = [
    {
      "subject": "LOCAL PARK",
      "HardWare": 120,
      "Software": 110,
      "fullMark": 150
    },
    {
      "subject": "SANTA LÚCIA SUL",
      "HardWare": 98,
      "Software": 130,
      "fullMark": 150
    },
    {
      "subject": "ONE PARKING",
      "HardWare": 86,
      "Software": 130,
      "fullMark": 150
    },
    {
      "subject": "CASA DE SÃO PAULO",
      "HardWare": 99,
      "Software": 100,
      "fullMark": 150
    },
    {
      "subject": "CITY OFFICE",
      "HardWare": 85,
      "Software": 90,
      "fullMark": 150
    },
    {
      "subject": "BARÃO DO RIO BRANCO",
      "HardWare": 65,
      "Software": 85,
      "fullMark": 10
    }
  ]

class Radars extends Component {
  
  render () {
    return (
      
      <ResponsiveContainer width={'100%'} height="45%">
        <RadarChart outerRadius={90} width={730} height={250} data={data}>
          <PolarGrid />
          <PolarAngleAxis dataKey="subject" />
          <PolarRadiusAxis angle={30} domain={[0, 150]} />
        <Radar 
            name="HardWare" 
            dataKey="HardWare" 
            stroke="#8884d8" 
            fill="#8884d8" 
            fillOpacity={0.6} />
        <Radar 
            name="Software" 
            dataKey="Software" 
            stroke="#82ca9d" 
            fill="#82ca9d" 
            fillOpacity={0.2} />
          <Tooltip />
          <Legend />
        </RadarChart>
      </ResponsiveContainer>
    );
  }
}

export default Radars;


