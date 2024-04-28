import React, { useState, useEffect } from 'react';
import { AgGridReact } from 'ag-grid-react';
import 'ag-grid-community/dist/styles/ag-grid.css';
import 'ag-grid-community/dist/styles/ag-theme-alpine.css';

const MyTable = ({ backendData }) => {
  const [rowData, setRowData] = useState([]);
  const [columnDefs, setColumnDefs] = useState([]);

  // Fetch data from backend and define column definitions on initial render
  useEffect(() => {
    // Simulate fetching data from backend (replace with your actual API call)
    const fetchedData = [
      { name: 'John Doe', age: 30, city: 'New York', department: 'Sales' },
      { name: 'Jane Smith', age: 25, city: 'Los Angeles', department: 'Marketing' },
      { name: 'Mike Brown', age: 40, city: 'Chicago', department: 'Engineering' },
      { name: 'Alice Johnson', age: 35, city: 'Seattle', department: 'Finance' },
    ];

    const formattedData = fetchedData.map((row) => ({ ...row })); // Avoid mutating original data
    setRowData(formattedData);

    setColumnDefs([
      { field: 'name', editable: false }, // Make name column non-editable
      { field: 'age', editable: (params) => params.rowIndex >= 1 && params.rowIndex <= 2 }, // Editable in rows 2 and 3
      { field: 'city', editable: (params) => params.rowIndex >= 1 && params.rowIndex <= 2 },
      { field: 'department', editable: (params) => params.rowIndex >= 1 && params.rowIndex <= 2 },
    ]);
  }, []);

  // Handle cell value changes (optional, for updating backend data)
  const onCellValueChanged = (params) => {
    const updatedRowData = [...rowData];
    updatedRowData[params.rowIndex][params.colDef.field] = params.newValue;
    setRowData(updatedRowData);

    // Send data updates to backend if needed (replace with your backend logic)
    console.log('Cell value changed:', params.newValue);
  };

  return (
    <div className="ag-theme-alpine" style={{ height: 400, width: '100%' }}>
      <AgGridReact
        rowData={rowData}
        columnDefs={columnDefs}
        defaultColDef={{
          cellDoubleClick: (params) => {
            const { editable } = params.columnDefs[params.columnIndex];
            if (editable) {
              params.api.startEditingCell(params.rowIndex, params.columnIndex);
            }
          },
        }}
        onCellValueChanged={onCellValueChanged}
      />
    </div>
  );
};

export default MyTable;
